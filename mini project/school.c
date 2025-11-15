#include <stdio.h>
#include <string.h>

#define MAX 100   // Maximum number of students

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student students[MAX];
    int count = 0;   // Number of students currently stored
    int choice;

    while (1) {
        printf("\n===== Student Record Management =====\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Update Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add Student
            if (count >= MAX) {
                printf("Record is full!\n");
                continue;
            }

            printf("Enter Roll Number: ");
            scanf("%d", &students[count].roll);

            printf("Enter Name: ");
            scanf("%s", students[count].name);

            printf("Enter Marks: ");
            scanf("%f", &students[count].marks);

            count++;
            printf("Student added successfully!\n");
        }

        else if (choice == 2) {
            // Search Student
            int r, found = 0;
            printf("Enter roll number to search: ");
            scanf("%d", &r);

            for (int i = 0; i < count; i++) {
                if (students[i].roll == r) {
                    printf("\nStudent Found:\n");
                    printf("Roll: %d\n", students[i].roll);
                    printf("Name: %s\n", students[i].name);
                    printf("Marks: %.2f\n", students[i].marks);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Student with roll %d not found.\n", r);
            }
        }

        else if (choice == 3) {
            // Update Student
            int r, found = 0;
            printf("Enter roll number to update: ");
            scanf("%d", &r);

            for (int i = 0; i < count; i++) {
                if (students[i].roll == r) {
                    printf("Enter new name: ");
                    scanf("%s", students[i].name);

                    printf("Enter new marks: ");
                    scanf("%f", &students[i].marks);

                    printf("Record updated successfully!\n");
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Student with roll %d not found.\n", r);
            }
        }

        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
