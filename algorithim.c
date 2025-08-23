#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    int age;
    char code[20];
    char email[100];
    char major[5];  
    int batch;      
    struct Student *next;
} 

Student;
Student *head = NULL;

// Function prototypes
void addnewStudent();
void listAllStudents();
void listStudentsByMajor();
void listStudentsByBatch();
void deleteStudentByCode();
void menu();

void addnewStudent() {
    Student *newStudent = (Student*)malloc(sizeof(Student));
    
    printf("Enter full name: ");
    getchar();
    fgets(newStudent->name, 100, stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = 0;

    printf("Enter age: ");
    scanf("%d", &newStudent->age);

    printf("Enter student code: ");
    scanf("%s", newStudent->code);

    printf("Enter email: ");
    scanf("%s", newStudent->email);

    printf("Enter major (RB, DS, AI, CB, SE): ");
    scanf("%s", newStudent->major);

    printf("Enter batch number (1, 2, or 3): ");
    scanf("%d", &newStudent->batch);

    newStudent->next = NULL;

    // Add to list
    if (head == NULL) {
        head = newStudent;
    } else {
        Student *current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = newStudent;
    }

    printf("Student added successfully.\n");
}
void listAllStudents() {
    if (head == NULL) {
        printf("No student data available.\n");
        return;
    }

    Student *current = head;

    printf("\n**** List Students ****\n");

    // Table header
    printf("================================================================================================\n");
    printf("| %-6s | %-20s | %-30s | %-15s | %-10s |\n", "Code", "Name", "Email", "Major", "Batch");
    printf("================================================================================================\n");

    // Table rows
    while (current != NULL) {
        printf("| %-6s | %-20s | %-30s | %-15s | %-10d |\n",
               current->code,
               current->name,
               current->email,
               current->major,  // Replace with phone if you add it in struct
               current->batch); // Replace with course count if you have it
        current = current->next;
    }

    printf("===============================================================================================\n");

}
void listStudentsByMajor() {
    char inputMajor[5];
    printf("Enter major to search (RB, DS, AI, CB, SE): ");
    scanf("%s", inputMajor);

    Student *current = head;        


  
    int found = 0;
    printf("\n%-20s %-3s %-10s %-25s %-4s %-5s\n", "Name", "Age", "Code", "Email", "Major", "Batch");
    
    while (current != NULL) {
        if (strcmp(current->major, inputMajor) == 0) {
            printf("%-20s %-3d %-10s %-25s %-4s %-5d\n",
                   current->name, current->age, current->code, current->email, current->major, current->batch);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
        printf("No students found with major: %s\n", inputMajor);
}
void listStudentsByBatch() {
    int inputBatch;
    printf("Enter batch number (1, 2, 3): ");
    scanf("%d", &inputBatch);

    Student *current = head;
    int found = 0;
    printf("\n%-20s %-3s %-10s %-25s %-4s %-5s\n", "Name", "Age", "Code", "Email", "Major", "Batch");

    while (current != NULL) {
        if (current->batch == inputBatch) {
            printf("%-20s %-3d %-10s %-25s %-4s %-5d\n",
                   current->name, current->age, current->code, current->email, current->major, current->batch);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
        printf("No students found in batch: %d\n", inputBatch);
}

void deleteStudentByCode() {
    char inputCode[20];
    printf("Enter student code to delete: ");
    scanf("%s", inputCode);

    Student *current = head;
    Student *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->code, inputCode) == 0) {
            if (prev == NULL)
                head = current->next;
            else
                prev->next = current->next;

            free(current);
            printf("Student with code %s deleted.\n", inputCode);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Student with code %s not found.\n", inputCode);
}

void menu() {
    int choice;
    do {
        printf("Student Management\n");
        printf("1. List all students\n");
        printf("2. List students by major\n");
        printf("3. List students by batch\n");
        printf("4. Add new student\n");
        printf("5. Delete student by code\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: listAllStudents(); break;
            case 2: listStudentsByMajor(); break;
            case 3: listStudentsByBatch(); break;
            case 4: addnewStudent(); break;
            case 5: deleteStudentByCode(); break;
            case 6:
                printf("Do you want to save changes before exiting? (y/n): ");
                char confirm;
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    printf("(Saving to file not implemented in this version.)\n");
                }
                printf("Exiting program.\n");
                break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
}
int main() {
    menu();
    return 0;
}
