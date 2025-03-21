import sqlite3

def initialize_database():
    conn = sqlite3.connect('marks.db')
    cursor = conn.cursor()

    cursor.execute('''CREATE TABLE IF NOT EXISTS students
                 (roll_number INTEGER PRIMARY KEY,
                  name TEXT NOT NULL,
                  sub1_marks INTEGER DEFAULT 0,
                  sub2_marks INTEGER DEFAULT 0,
                  sub3_marks INTEGER DEFAULT 0,
                  total_marks INTEGER DEFAULT 0)''')

    conn.commit()
    conn.close()

def add_student(roll_number, name):
    conn = sqlite3.connect('marks.db')
    cursor = conn.cursor()
    cursor.execute("INSERT INTO students (roll_number, name) VALUES (?, ?)", (roll_number, name))
    conn.commit()
    conn.close()

def update_marks(roll_number, subject, marks):
    conn = sqlite3.connect('marks.db')
    cursor = conn.cursor()

    if subject == "sub1":
        cursor.execute("UPDATE students SET sub1_marks = ? WHERE roll_number = ?", (marks, roll_number))
    elif subject == "sub2":
        cursor.execute("UPDATE students SET sub2_marks = ? WHERE roll_number = ?", (marks, roll_number))
    elif subject == "sub3":
        cursor.execute("UPDATE students SET sub3_marks = ? WHERE roll_number = ?", (marks, roll_number))

    cursor.execute("UPDATE students SET total_marks = (sub1_marks + sub2_marks + sub3_marks) WHERE roll_number = ?", (roll_number,))

    conn.commit()
    conn.close()

def sort_database():
    conn = sqlite3.connect('marks.db')
    cursor = conn.cursor()

    cursor.execute("SELECT * FROM students ORDER BY total_marks DESC")

    result = cursor.fetchall()
    conn.close()
    return result

def display_students(student_data):
    print "| {:<20} | {:<10} | {:<12} | {:<12} | {:<12} | {:<12} |".format("Name", "RollNo", "Subject 1", "Subject 2", "Subject 3", "Total Marks")
    print "-"*100
    for student in student_data:
        print "| {:<20} | {:<10} | {:<12} | {:<12} | {:<12} | {:<12} |".format(student[1], student[0], student[2], student[3], student[4], student[5])

def display_menu():
    print "\nMenu:"
    print "1. Add Student"
    print "2. Update Marks"
    print "3. View Student Information"
    print "4. Exit"

def main():
    initialize_database()

    while True:
        display_menu()
        choice = raw_input("Enter your choice: ")

        if choice == '1':
            roll_number = int(raw_input("Enter roll number: "))
            name = raw_input("Enter name: ")
            add_student(roll_number, name)
            print "Student added successfully."

        elif choice == '2':
            roll_number = int(raw_input("Enter roll number: "))
            subject = raw_input("Enter subject (sub1/sub2/sub3): ")
            marks = int(raw_input("Enter marks for {0}: ".format(subject)))
            update_marks(roll_number, subject, marks)
            print "Marks updated successfully."

        elif choice == '3':
            student_data = sort_database()
            display_students(student_data)

        elif choice == '4':
            print "Exiting program."
            break

        else:
            print "Invalid choice. Please try again."

if __name__ == "__main__":
    main()

