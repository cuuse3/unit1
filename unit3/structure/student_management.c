#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
struct Student {
    int roll_no;
    char name[50];
    float marks;
};

// Function prototypes
void addStudent();
void searchStudent();
void removeStudent();
void displayAllStudents();

int main() {
    int choice;
    
    while(1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Remove Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                removeStudent();
                break;
            case 4:
                displayAllStudents();
                break;
            case 5:
                printf("Thank you for using the program!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    FILE *fp;
    struct Student student;
    
    fp = fopen("students.dat", "ab");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("Enter Roll No: ");
    scanf("%d", &student.roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]s", student.name);
    printf("Enter Marks: ");
    scanf("%f", &student.marks);
    
    fwrite(&student, sizeof(struct Student), 1, fp);
    printf("Student record added successfully!\n");
    
    fclose(fp);
}

void searchStudent() {
    FILE *fp;
    struct Student student;
    int roll, found = 0;
    
    fp = fopen("students.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);
    
    while(fread(&student, sizeof(struct Student), 1, fp)) {
        if(student.roll_no == roll) {
            printf("\nStudent Found!\n");
            printf("Roll No: %d\n", student.roll_no);
            printf("Name: %s\n", student.name);
            printf("Marks: %.2f\n", student.marks);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Student not found!\n");
    }
    
    fclose(fp);
}

void removeStudent() {
    FILE *fp, *temp;
    struct Student student;
    int roll, found = 0;
    
    fp = fopen("students.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    temp = fopen("temp.dat", "wb");
    if(temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }
    
    printf("Enter Roll No to remove: ");
    scanf("%d", &roll);
    
    while(fread(&student, sizeof(struct Student), 1, fp)) {
        if(student.roll_no == roll) {
            found = 1;
            continue;
        }
        fwrite(&student, sizeof(struct Student), 1, temp);
    }
    
    fclose(fp);
    fclose(temp);
    
    if(found) {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        printf("Student record deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("Student not found!\n");
    }
}

void displayAllStudents() {
    FILE *fp;
    struct Student student;
    int count = 0;
    
    fp = fopen("students.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("\nAll Students:\n");
    printf("----------------------------------------\n");
    printf("Roll No\tName\t\tMarks\n");
    printf("----------------------------------------\n");
    
    while(fread(&student, sizeof(struct Student), 1, fp)) {
        printf("%d\t%s\t\t%.2f\n", student.roll_no, student.name, student.marks);
        count++;
    }
    
    if(count == 0) {
        printf("No records found!\n");
    }
    printf("----------------------------------------\n");
    
    fclose(fp);
}