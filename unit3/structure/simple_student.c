#include <stdio.h>

// Simple structure for student
struct Student {
    int roll;
    char name[30];
    float marks;
};

int main() {
    FILE *file;
    struct Student student;
    int choice;
    
    while(1) {
        printf("\n=== Simple Student Record System ===\n");
        printf("1: Add student\n");
        printf("2: View all students\n");
        printf("3: Exit\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            // Open file in append mode
            file = fopen("students.txt", "a");
            
            printf("Enter roll number: ");
            scanf("%d", &student.roll);
            
            printf("Enter name: ");
            scanf(" %[^\n]s", student.name);
            
            printf("Enter marks: ");
            scanf("%f", &student.marks);
            
            // Write to file
            fprintf(file, "%d %s %.2f\n", student.roll, student.name, student.marks);
            printf("Student added successfully!\n");
            
            fclose(file);
        }
        else if(choice == 2) {
            // Open file in read mode
            file = fopen("students.txt", "r");
            
            if(file == NULL) {
                printf("No records found!\n");
                continue;
            }
            
            printf("\nStudent Records:\n");
            printf("Roll\tName\t\tMarks\n");
            printf("------------------------\n");
            
            // Read and display each record
            while(fscanf(file, "%d %s %f", &student.roll, student.name, &student.marks) != EOF) {
                printf("%d\t%s\t\t%.2f\n", student.roll, student.name, student.marks);
            }
            
            fclose(file);
        }
        else if(choice == 3) {
            printf("Thank you for using the program!\n");
            break;
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}