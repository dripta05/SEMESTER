import java.util.Scanner;
import java.util.ArrayList;

class Person {
    String name;
    int age;
    double weight;
    double height;
    String dateOfBirth;
    String address;

    public Person(String name, int age, double weight, double height, String dateOfBirth, String address) {
        this.name = name;
        this.age = age;
        this.weight = weight;
        this.height = height;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
    }

    public void displayPersonInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Weight: " + weight);
        System.out.println("Height: " + height);
        System.out.println("Date of Birth: " + dateOfBirth);
        System.out.println("Address: " + address);
    }
}

class Employee extends Person {
    double salary;
    String dateOfJoining;
    int experience;

    public Employee(String name, int age, double weight, double height, String dateOfBirth, String address,
                    double salary, String dateOfJoining, int experience) {
        super(name, age, weight, height, dateOfBirth, address);
        this.salary = salary;
        this.dateOfJoining = dateOfJoining;
        this.experience = experience;
    }

    public void displayEmployeeInfo() {
        displayPersonInfo();
        System.out.println("Salary: " + salary);
        System.out.println("Date of Joining: " + dateOfJoining);
        System.out.println("Experience: " + experience + " years");
    }
}

class Student extends Person {
    int roll;
    ArrayList<String> listOfSubjects = new ArrayList<>();
    ArrayList<Integer> marks = new ArrayList<>();

    public Student(String name, int age, double weight, double height, String dateOfBirth, String address, int roll) {
        super(name, age, weight, height, dateOfBirth, address);
        this.roll = roll;
    }

    public void addSubject(String subject, int mark) {
        listOfSubjects.add(subject);
        marks.add(mark);
    }

    public String calculateGrade() {
        double totalMarks = 0;
        for (int mark : marks) {
            totalMarks += mark;
        }
        double average = totalMarks / marks.size();

        if (average >= 90) return "A";
        else if (average >= 75) return "B";
        else if (average >= 50) return "C";
        else return "D";
    }

    public void displayStudentInfo() {
        displayPersonInfo();
        System.out.println("Roll No: " + roll);
        System.out.println("Subjects and Marks:");
        for (int i = 0; i < listOfSubjects.size(); i++) {
            System.out.println(listOfSubjects.get(i) + ": " + marks.get(i));
        }
        System.out.println("Grade: " + calculateGrade());
    }
}

class Technician extends Employee {
    public Technician(String name, int age, double weight, double height, String dateOfBirth, String address,
                      double salary, String dateOfJoining, int experience) {
        super(name, age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
    }

    public void displayTechnicianInfo() {
        displayEmployeeInfo();
        System.out.println("Technician is responsible for hands-on tasks and maintenance.");
    }
}

class Professor extends Employee {
    ArrayList<String> courses = new ArrayList<>();
    ArrayList<String> listOfAdvisees = new ArrayList<>();

    public Professor(String name, int age, double weight, double height, String dateOfBirth, String address,
                     double salary, String dateOfJoining, int experience) {
        super(name, age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
    }

    public void addCourse(String course) {
        courses.add(course);
    }

    public void addAdvisee(String advisee) {
        listOfAdvisees.add(advisee);
    }

    public void removeAdvisee(String advisee) {
        listOfAdvisees.remove(advisee);
    }

    public void displayProfessorInfo() {
        displayEmployeeInfo();
        System.out.println("Courses: " + courses);
        System.out.println("Advisees: " + listOfAdvisees);
    }
}
 class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter Student Details:");
        System.out.print("Name: ");
        String name = scanner.nextLine();
        System.out.print("Age: ");
        int age = scanner.nextInt();
        System.out.print("Weight: ");
        double weight = scanner.nextDouble();
        System.out.print("Height: ");
        double height = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("Date of Birth: ");
        String dob = scanner.nextLine();
        System.out.print("Address: ");
        String address = scanner.nextLine();
        System.out.print("Roll No: ");
        int roll = scanner.nextInt();
        Student student = new Student(name, age, weight, height, dob, address, roll);

        scanner.nextLine();
        String moreSubjects;
        do {
            System.out.print("Enter Subject: ");
            String subject = scanner.nextLine();
            System.out.print("Enter Marks: ");
            int mark = scanner.nextInt();
            student.addSubject(subject, mark);
            scanner.nextLine();
            System.out.print("Do you want to add more subjects? (yes/no): ");
            moreSubjects = scanner.nextLine();
        } while (moreSubjects.equalsIgnoreCase("yes"));

        student.displayStudentInfo();

        System.out.println("\nEnter Employee (Technician) Details:");
        System.out.print("Name: ");
        name = scanner.nextLine();
        System.out.print("Age: ");
        age = scanner.nextInt();
        System.out.print("Weight: ");
        weight = scanner.nextDouble();
        System.out.print("Height: ");
        height = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("Date of Birth: ");
        dob = scanner.nextLine();
        System.out.print("Address: ");
        address = scanner.nextLine();
        System.out.print("Salary: ");
        double salary = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("Date of Joining: ");
        String doj = scanner.nextLine();
        System.out.print("Experience (in years): ");
        int experience = scanner.nextInt();
        Technician technician = new Technician(name, age, weight, height, dob, address, salary, doj, experience);

        technician.displayTechnicianInfo();

        System.out.println("\nEnter Employee (Professor) Details:");
        System.out.print("Name: ");
        name = scanner.nextLine();
        System.out.print("Age: ");
        age = scanner.nextInt();
        System.out.print("Weight: ");
        weight = scanner.nextDouble();
        System.out.print("Height: ");
        height = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("Date of Birth: ");
        dob = scanner.nextLine();
        System.out.print("Address: ");
        address = scanner.nextLine();
        System.out.print("Salary: ");
        salary = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("Date of Joining: ");
        doj = scanner.nextLine();
        System.out.print("Experience (in years): ");
        experience = scanner.nextInt();
        Professor professor = new Professor(name, age, weight, height, dob, address, salary, doj, experience);

        scanner.nextLine();
        System.out.print("Enter a Course for the Professor: ");
        String course = scanner.nextLine();
        professor.addCourse(course);
        System.out.print("Enter an Advisee for the Professor: ");
        String advisee = scanner.nextLine();
        professor.addAdvisee(advisee);

        professor.displayProfessorInfo();

        scanner.close();
    }
}

