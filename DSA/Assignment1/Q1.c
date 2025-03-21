#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 2
#define SUBJECTS 5

// Structure to hold student information
struct Student {
    char name[50];
    char address[100];
    int marks[SUBJECTS];
};

// Function prototypes
void inputStudentData(struct Student *students, int count);
void displayPassedFailed(struct Student *students, int count);
void displayMaxMaths(struct Student *students, int count);
void displayMinPhysics(struct Student *students, int count);
void displayMaxAverage(struct Student *students, int count);
void displayTotalMarks(struct Student *students, int count);
int main() {
    struct Student students[MAX_STUDENTS];
    int choice;

    // Input student data
    inputStudentData(students, MAX_STUDENTS);
    do {
        printf("\nMenu:\n");
        printf("1. Find students who passed/failed in minimum three subjects\n");
        printf("2. Show record of the student with maximum marks in Mathematics\n");
        printf("3. Show record of the student with minimum marks in Physics\n");
        printf("4. Show record of the student with maximum average marks\n");
        printf("5. Print record of students with name and total marks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPassedFailed(students, MAX_STUDENTS);
                break;
            case 2:
                displayMaxMaths(students, MAX_STUDENTS);
                break;
            case 3:
                displayMinPhysics(students, MAX_STUDENTS);
                break;
            case 4:
                break;
            case 5:
                displayTotalMarks(students, MAX_STUDENTS);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
// Function to input student data
void inputStudentData(struct Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Address: ");
        scanf(" %[^\n]", students[i].address);
        printf("Enter marks for five subjects:\n");
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }
}
// Function to display students who passed/failed in minimum three subjects
void displayPassedFailed(struct Student *students, int count) {
    printf("\nStudents who passed and failed in minimum three subjects:\n");
    for (int i = 0; i < count; i++) {
        int passCount = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            if (students[i].marks[j] >= 40) {
                passCount++;
            }
        }
        if (passCount >= 3) {
            printf("%s: Passed\n", students[i].name);
        } else {
            printf("%s: Failed\n", students[i].name);
        }
    }
}
// Function to display the student with maximum marks in Mathematics
void displayMaxMaths(struct Student *students, int count) {
    int maxIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].marks[0] > students[maxIndex].marks[0]) {
            maxIndex = i;
        }
    }
    printf("\nStudent with maximum marks in Mathematics:\n");
    printf("Name: %s\n", students[maxIndex].name);
    printf("Address: %s\n", students[maxIndex].address);
    printf("Marks in Mathematics: %d\n", students[maxIndex].marks[0]);
}

// Function to display the student with minimum marks in Physics
void displayMinPhysics(struct Student *students, int count) {
    int minIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].marks[1] < students[minIndex].marks[1]) {
            minIndex = i;
        }
    }
    printf("\nStudent with minimum marks in Physics:\n");
    printf("Name: %s\n", students[minIndex].name);
    printf("Address: %s\n", students[minIndex].address);
    printf("Marks in Physics: %d\n", students[minIndex].marks[1]);
}
void displayMaxAverage(struct Student *students, int count) {
    int maxIndex = 0;
    float maxAverage = 0.0;
    for (int i = 0; i < count; i++) {
        float total = 0.0;
        for (int j = 0; j < SUBJECTS; j++) {
            total += students[i].marks[j];
        }
        float average = total / SUBJECTS;
        if (average > maxAverage) {
            maxAverage = average;
            maxIndex = i;
        }
    }
    printf("\nStudent with maximum average marks:\n");
    printf("Name: %s\n", students[maxIndex].name);
    printf("Address: %s\n", students[maxIndex].address);
    printf("Average Marks: %.2f\n", maxAverage);
}

// Function to print records of students with total marks
void displayTotalMarks(struct Student *students, int count) {
    printf("\nRecords of students with total marks:\n");
    for (int i = 0; i < count; i++) {
        int total = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            total += students[i].marks[j];
        }
        printf("Name: %s, Total Marks: %d\n", students[i].name, total);
    }
}
