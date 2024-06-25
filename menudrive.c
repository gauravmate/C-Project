#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct signup
{
    char username[30];
    char password[10];
};

struct student
{
    char name[20];
    char si_id[20];
    char role[20];
    int marks[6];
    float percentage;
};

void signup(struct signup *signup)
{
    printf("\nEnter username for signup:\n");
    scanf("%s", signup->username);
    printf("\nEnter user password:\n");
    scanf("%s", signup->password);
}

int login(struct signup *log)
{
    char userName[30];
    char pass[10];
    printf("\nEnter username for login:\n");
    scanf("%s", userName);
    printf("\nEnter password for login:\n");
    scanf("%s", pass);

    if (strcmp(userName, log->username) == 0 && strcmp(pass, log->password) == 0)
    {
        printf("\nLogin successful.... ");
        return 1;
    }
    else
    {
        printf("\nLogin failed. Incorrect username or password.\n");
        return 0;
    }
}

void exits()
{
    printf("\nProgram is Terminate\n");
}

void Addstudent(struct student **students, int *student_count)
{
    *students = realloc(*students, (*student_count + 1) * sizeof(struct student));
    if (*students == NULL)
    {
        printf("\nMemory allocation failed\n");
        exit(1);
    }

    printf("\nEnter the student name:");
    scanf("%s", (*students)[*student_count].name);
    printf("\nEnter the Student SI ID:");
    scanf("%s", (*students)[*student_count].si_id);

    int role_choice;
    printf("\nSelect the student Field:\n");
    printf("1. Web Developer\n2. Testing\n3. Java Developer\n");
    printf("Enter your choice: ");
    scanf("%d", &role_choice);

    switch (role_choice)
    {
    case 1:
        strcpy((*students)[*student_count].role, "Web Developer");
        printf("\nEnter the marks for the following subjects for Web Developer:\n");
        printf("1. C Programming: ");
        scanf("%d", &(*students)[*student_count].marks[0]);
        printf("2. SQL: ");
        scanf("%d", &(*students)[*student_count].marks[1]);
        printf("3. Mongo DB: ");
        scanf("%d", &(*students)[*student_count].marks[2]);
        printf("4. RWD: ");
        scanf("%d", &(*students)[*student_count].marks[3]);
        printf("5. Node Js: ");
        scanf("%d", &(*students)[*student_count].marks[4]);
        printf("6. PHP: ");
        scanf("%d", &(*students)[*student_count].marks[5]);
        break;
    case 2:
        strcpy((*students)[*student_count].role, "Testing");
        printf("\nEnter the marks for the following subjects for Testing:\n");
        printf("1. C Programming: ");
        scanf("%d", &(*students)[*student_count].marks[0]);
        printf("2. SQL: ");
        scanf("%d", &(*students)[*student_count].marks[1]);
        printf("3. Mongo DB: ");
        scanf("%d", &(*students)[*student_count].marks[2]);
        printf("4. Java: ");
        scanf("%d", &(*students)[*student_count].marks[3]);
        printf("5. Node Js: ");
        scanf("%d", &(*students)[*student_count].marks[4]);
        printf("6. Angular: ");
        scanf("%d", &(*students)[*student_count].marks[5]);
        break;
    case 3:
        strcpy((*students)[*student_count].role, "Java Developer");
        printf("\nEnter the marks for the following subjects for Java Developer:\n");
        printf("1. C Programming: ");
        scanf("%d", &(*students)[*student_count].marks[0]);
        printf("2. SQL: ");
        scanf("%d", &(*students)[*student_count].marks[1]);
        printf("3. Java: ");
        scanf("%d", &(*students)[*student_count].marks[2]);
        printf("4. AL: ");
        scanf("%d", &(*students)[*student_count].marks[3]);
        printf("5. Node Js: ");
        scanf("%d", &(*students)[*student_count].marks[4]);
        printf("6. React Js: ");
        scanf("%d", &(*students)[*student_count].marks[5]);
        break;
    default:
        printf("Invalid choice. Role set to 'Unknown'.\n");
        strcpy((*students)[*student_count].role, "Unknown");
        break;
    }

    // Calculate percentage
    int total_marks = 0;
    for (int i = 0; i < 6; i++)
    {
        total_marks += (*students)[*student_count].marks[i];
    }
    (*students)[*student_count].percentage = (total_marks / 6.0);

    printf("\nStudent details added successfully!\n");
    printf("Name: %s\n", (*students)[*student_count].name);
    printf("SI ID: %s\n", (*students)[*student_count].si_id);
    printf("Role: %s\n", (*students)[*student_count].role);
    printf("Percentage: %.2f\n", (*students)[*student_count].percentage);

    (*student_count)++;
}

void showstudentdetails(struct student *students, int student_count)
{
    if (student_count == 0)
    {
        printf("\nNo student data available.\n");
    }
    else
    {
        printf("\n%-20s %-20s %-20s %-20s %-20s\n", "Name", "SI ID", "Role", "Marks", "Percentage");
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < student_count; i++)
        {
            printf("%-20s %-20s %-20s", students[i].name, students[i].si_id, students[i].role);
            for (int j = 0; j < 6; j++)
            {
                printf("%-4d ", students[i].marks[j]);
            }
            printf("%-20.2f\n", students[i].percentage);
        }
    }
}

void exitfun()
{
    printf("\nFunction is Terminate\n");
}

int main()
{
    struct signup sign;
    struct student *students = NULL;
    int student_count = 0;
    int choice;
    int continuep = 1;

    while (continuep)
    {
        printf("\n*WELCOME TO SEED PORTAL*\n");
        printf("\n1. Signup \n2. Login \n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            signup(&sign);
            printf("\nUsername: %s\n", sign.username);
            printf("Password: %s\n", sign.password);

            if (login(&sign))
            {
                while (1)
                {
                    printf("\n1. Add student \n2. Show student details \n3. Exit");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                        Addstudent(&students, &student_count);
                    }
                    else if (choice == 2)
                    {
                        showstudentdetails(students, student_count);
                    }
                    else if (choice == 3)
                    {
                        exitfun();
                        break;
                    }
                    else
                    {
                        printf("Invalid choice. Please enter 1, 2, or 3.\n");
                    }
                }
            }
        }
        else if (choice == 2)
        {
            if (login(&sign))
            {
                while (1)
                {
                    printf("\n1. Add student \n2. Show student details \n3. Exit");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                        Addstudent(&students, &student_count);
                    }
                    else if (choice == 2)
                    {
                        showstudentdetails(students, student_count);
                    }
                    else if (choice == 3)
                    {
                        exitfun();
                        break;
                    }
                    else
                    {
                        printf("Invalid choice. Please enter 1, 2, or 3.\n");
                    }
                }
            }
        }
        else if (choice == 3)
        {
            exits();
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

        printf("\nDo you want to continue? 1 for Yes, 0 for No: ");
        scanf("%d", &continuep);
    }

    free(students);

    printf("\nProgram terminated.....!\n");
    return 0;
}
