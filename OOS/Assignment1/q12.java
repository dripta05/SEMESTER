import java.util.Scanner;

class Student {
    String name;
    int rollNo;
    String[] subjects = new String[5];

    public Student(String name, int rollNo, String[] subjects) {
        this.name = name;
        this.rollNo = rollNo;
        this.subjects = subjects;
    }

    public String getName() {
        return name;
    }

    public int getRollNo() {
        return rollNo;
    }

    public String[] getSubjects() {
        return subjects;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setRollNo(int rollNo) {
        this.rollNo = rollNo;
    }

    public void setSubjects(String[] subjects) {
        this.subjects = subjects;
    }
}

class TabulationSheet {
    int rollNo;
    int[] marks = new int[5];

    public TabulationSheet(int rollNo) {
        this.rollNo = rollNo;
    }

    public void addMarks(int[] marks) {
        this.marks = marks;
    }

    public int[] getMarks() {
        return marks;
    }

    public int getRollNo() {
        return rollNo;
    }
}

class MarkSheet {
    Student student;
    TabulationSheet tabulationSheet;

    public MarkSheet(Student student, TabulationSheet tabulationSheet) {
        this.student = student;
        this.tabulationSheet = tabulationSheet;
    }

    public void printMarkSheet() {
        System.out.println("Mark Sheet for Student: " + student.getName() + " (Roll No: " + student.getRollNo() + ")");
        System.out.println("------------------------------------------------------");
        String[] subjects = student.getSubjects();
        int[] marks = tabulationSheet.getMarks();
        for (int i = 0; i < 5; i++) {
            System.out.println(subjects[i] + ": " + marks[i]);
        }
        System.out.println("------------------------------------------------------");
    }
}
 class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] subjects = {"Math", "Science", "English", "History", "Geography"};

        Student student1 = new Student("Alice", 1, subjects);
        Student student2 = new Student("Bob", 2, subjects);
        Student student3 = new Student("Charlie", 3, subjects);

        TabulationSheet tabulationSheet1 = new TabulationSheet(student1.getRollNo());
        TabulationSheet tabulationSheet2 = new TabulationSheet(student2.getRollNo());
        TabulationSheet tabulationSheet3 = new TabulationSheet(student3.getRollNo());

         System.out.println("Enter marks for student 1 (Alice):");
        int[] marks1 = new int[5];
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter marks for " + subjects[i] + ": ");
            marks1[i] = scanner.nextInt();
        }
        tabulationSheet1.addMarks(marks1);

        System.out.println("Enter marks for student 2 (Bob):");
        int[] marks2 = new int[5];
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter marks for " + subjects[i] + ": ");
            marks2[i] = scanner.nextInt();
        }
        tabulationSheet2.addMarks(marks2);

        System.out.println("Enter marks for student 3 (Charlie):");
        int[] marks3 = new int[5];
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter marks for " + subjects[i] + ": ");
            marks3[i] = scanner.nextInt();
        }
        tabulationSheet3.addMarks(marks3);

        MarkSheet markSheet1 = new MarkSheet(student1, tabulationSheet1);
        MarkSheet markSheet2 = new MarkSheet(student2, tabulationSheet2);
        MarkSheet markSheet3 = new MarkSheet(student3, tabulationSheet3);

        markSheet1.printMarkSheet();
        markSheet2.printMarkSheet();
        markSheet3.printMarkSheet();

        scanner.close();
    }
}


