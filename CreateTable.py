import sqlite3
import os

# -------------------------- Configuration --------------------------
# Database file name
DB_FILE = "table.db"
# Data source folder name
DATA_FOLDER = "module_project2"
# Paths for 4 data source files
FILE_PATHS = {
    "module": os.path.join(DATA_FOLDER, "module.txt"),
    "student": os.path.join(DATA_FOLDER, "student.txt"),
    "staff": os.path.join(DATA_FOLDER, "staff.txt"),
    "score": os.path.join(DATA_FOLDER, "score.txt")
}
# File encoding, change to gbk/gb2312 if reading garbled characters
FILE_ENCODING = "gbk"
# Whether to clear the database and restart every run (True=overwrite, False=append)
OVERWRITE_MODE = True  # <--- Toggle mode here

# -------------------------- Database Table Creation SQL --------------------------
CREATE_TABLE_SQL = [
    # 1. Course information table
    """
    CREATE TABLE IF NOT EXISTS courses (
        course_id TEXT PRIMARY KEY,
        course_name TEXT NOT NULL,
        credit REAL NOT NULL,
        hours INTEGER NOT NULL,
        course_type TEXT NOT NULL
    );
    """,
    # 2. Student information table
    """
    CREATE TABLE IF NOT EXISTS students (
        student_id TEXT PRIMARY KEY,
        name TEXT NOT NULL,
        class TEXT NOT NULL,
        major TEXT NOT NULL
    );
    """,
    # 3. Staff information table
    """
    CREATE TABLE IF NOT EXISTS staff (
        staff_id TEXT PRIMARY KEY,
        name TEXT NOT NULL,
        courses_taught TEXT NOT NULL
    );
    """,
    # 4. Student score table
    """
    CREATE TABLE IF NOT EXISTS scores (
        record_id INTEGER PRIMARY KEY AUTOINCREMENT,
        student_id TEXT NOT NULL,
        student_name TEXT NOT NULL,
        course_name TEXT NOT NULL,
        score INTEGER NOT NULL
    );
    """,
    # 5. Account management table
    """
    CREATE TABLE IF NOT EXISTS accounts (
        account_id TEXT PRIMARY KEY,
        name TEXT NOT NULL,
        password TEXT NOT NULL DEFAULT '123456',
        role TEXT NOT NULL CHECK(role IN ('student', 'teacher', 'admin'))
    );
    """
]

# -------------------------- Data Processing Functions --------------------------
def read_and_clean_file(file_path):
    """Read file, filter comment lines, blank lines, end marker lines"""
    if not os.path.exists(file_path):
        print(f"Error: File {file_path} does not exist, please check the path")
        return []
    clean_lines = []
    with open(file_path, "r", encoding=FILE_ENCODING, errors="ignore") as f:
        for line in f:
            line = line.strip()
            # Skip comment lines, blank lines, end lines
            if not line or line.startswith("#") or line == "#END":
                continue
            clean_lines.append(line)
    return clean_lines

def import_courses(cursor, file_path):
    """Import course data"""
    lines = read_and_clean_file(file_path)
    if not lines:
        return
    insert_data = []
    for line in lines:
        parts = line.split()
        if len(parts) < 5:
            print(f"Abnormal course data format, skip this line: {line}")
            continue
        # Split fields: course ID, course name, credit, hours, course type
        course_id = parts[0]
        course_name = parts[1]
        # Handle special characters in course name (such as parentheses) to ensure correct field splitting
        if len(parts) > 5:
            course_name = " ".join(parts[1:-3])
            credit = parts[-3]
            hours = parts[-2]
            course_type = parts[-1]
        else:
            credit = parts[2]
            hours = parts[3]
            course_type = parts[4]
        # Type conversion
        try:
            credit = float(credit)
            hours = int(hours)
        except ValueError:
            print(f"Course data type conversion failed, skip this line: {line}")
            continue
        insert_data.append((course_id, course_name, credit, hours, course_type))
    # Batch insert, duplicate primary keys are automatically ignored
    cursor.executemany("INSERT OR IGNORE INTO courses VALUES (?,?,?,?,?)", insert_data)
    print(f"Course data import completed, total {cursor.rowcount} records inserted")

def import_students(cursor, file_path):
    """Import student data"""
    lines = read_and_clean_file(file_path)
    if not lines:
        return
    insert_data = []
    for line in lines:
        parts = line.split()
        if len(parts) != 4:
            print(f"Abnormal student data format, skip this line: {line}")
            continue
        student_id, name, class_name, major = parts
        insert_data.append((student_id, name, class_name, major))
    cursor.executemany("INSERT OR IGNORE INTO students VALUES (?,?,?,?)", insert_data)
    print(f"Student data import completed, total {cursor.rowcount} records inserted")

def import_staff(cursor, file_path):
    """Import staff data"""
    lines = read_and_clean_file(file_path)
    if not lines:
        return
    insert_data = []
    for line in lines:
        parts = line.split()
        if len(parts) < 3:
            print(f"Abnormal staff data format, skip this line: {line}")
            continue
        staff_id = parts[0]
        name = parts[1]
        # Merge taught courses into a comma-separated string
        courses_taught = ",".join(parts[2:])
        insert_data.append((staff_id, name, courses_taught))
    cursor.executemany("INSERT OR IGNORE INTO staff VALUES (?,?,?)", insert_data)
    print(f"Staff data import completed, total {cursor.rowcount} records inserted")

def import_scores(cursor, file_path):
    """Import score data"""
    lines = read_and_clean_file(file_path)
    if not lines:
        return
    insert_data = []
    for line in lines:
        parts = line.split()
        if len(parts) < 4:
            print(f"Abnormal score data format, skip this line: {line}")
            continue
        student_id = parts[0]
        student_name = parts[1]
        score = parts[-1]
        # Handle special characters in course name
        if len(parts) > 4:
            course_name = " ".join(parts[2:-1])
        else:
            course_name = parts[2]
        # Type conversion
        try:
            score = int(score)
        except ValueError:
            print(f"Score data type conversion failed, skip this line: {line}")
            continue
        insert_data.append((student_id, student_name, course_name, score))
    cursor.executemany("INSERT OR IGNORE INTO scores (student_id, student_name, course_name, score) VALUES (?,?,?,?)", insert_data)
    print(f"Score data import completed, total {cursor.rowcount} records inserted")

def import_accounts(cursor):
    """Import account data: extract from student and staff tables, add default admin"""
    # 1. Import student accounts from students table (role: student)
    cursor.execute("SELECT student_id, name FROM students")
    students = cursor.fetchall()
    student_accounts = [(sid, name, "123456", "student") for sid, name in students]
    cursor.executemany("INSERT OR IGNORE INTO accounts VALUES (?,?,?,?)", student_accounts)
    print(f"Student account import completed, total {len(student_accounts)} records processed (duplicates automatically ignored)")

    # 2. Import teacher accounts from staff table (role: teacher)
    cursor.execute("SELECT staff_id, name FROM staff")
    staffs = cursor.fetchall()
    staff_accounts = [(sid, name, "123456", "teacher") for sid, name in staffs]
    cursor.executemany("INSERT OR IGNORE INTO accounts VALUES (?,?,?,?)", staff_accounts)
    print(f"Teacher account import completed, total {len(staff_accounts)} records processed (duplicates automatically ignored)")

    # 3. Add default admin account (role: admin)
    admin_account = ("admin", "System Admin", "123456", "admin")
    cursor.execute("INSERT OR IGNORE INTO accounts VALUES (?,?,?,?)", admin_account)
    print("Default admin account configured (account: admin, password: 123456)")

# -------------------------- Main Execution Logic --------------------------
def main():
    # Check if the data folder exists
    if not os.path.exists(DATA_FOLDER):
        print(f"Error: Data folder {DATA_FOLDER} does not exist, please confirm the directory structure")
        return

    # [Overwrite Mode] If overwrite mode is enabled and the database file exists, delete it first
    if OVERWRITE_MODE and os.path.exists(DB_FILE):
        try:
            os.remove(DB_FILE)
            print(f"Overwrite mode enabled, old database file {DB_FILE} has been deleted")
        except Exception as e:
            print(f"Failed to delete old database file, please close the file first: {str(e)}")
            return

    # Connect to the database (automatically created if it does not exist)
    conn = sqlite3.connect(DB_FILE)
    cursor = conn.cursor()
    print(f"Successfully connected to database {DB_FILE}")

    try:
        # 1. Create all tables
        for sql in CREATE_TABLE_SQL:
            cursor.execute(sql)
        print("Database table creation completed (including account management table)")

        # 2. Import data in dependency order (main tables first, then slave tables, finally account table)
        import_students(cursor, FILE_PATHS["student"])
        import_courses(cursor, FILE_PATHS["module"])
        import_staff(cursor, FILE_PATHS["staff"])
        import_scores(cursor, FILE_PATHS["score"])
        # Account table depends on student and staff tables, must be imported after them
        import_accounts(cursor)

        # Commit transaction
        conn.commit()
        print("\nAll data import completed!")

    except Exception as e:
        conn.rollback()
        print(f"Data import failed, transaction has been rolled back, error message: {str(e)}")
    finally:
        # Close connection
        cursor.close()
        conn.close()
        print("Database connection closed")

if __name__ == "__main__":
    main()