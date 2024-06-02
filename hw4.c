#include <stdio.h>// Standard Input Output library
#include <stdlib.h>// Standard library, includes memory allocation, process control, etc.
#include <conio.h>// // Console Input Output (specific to Windows)
#include <stdbool.h>// Boolean type support
#include <string.h>// String manipulation functions
#include <ctype.h>// Character type functions
#include <unistd.h>// Unix standard functions 
#include <time.h>// Time related functions

#define MAX_STUDENT 10 // Maximum number of students
#define MIN_STUDENT 2 // Minimum number of students

void clear_screen();
bool checkPassword();
void mainMenu();
void personalScreen();
void inputData();
void displayData();
void searchGrade();
void sort_student();
void gradeRanking();
char getInput();

typedef struct {
    char name[30];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student student[MAX_STUDENT];
int studentCount = 0;

void clear_screen() {
    system("cls");
}

void personalScreen() {
    printf("****************************************************************************\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
	printf("*                     Created by H1.06ªL¬L¥ì                               *\n");
	printf("*                                                                          *\n");
	printf("*                                                                          *\n");
	printf("*                                                                          *\n");
    printf("*                         /\\_/\\                                          *\n");                                 
    printf("*                        ( o   o )                                         *\n");
    printf("*                       =(  =^=  )=                                        *\n");
    printf("*                         )     (                                          *\n");
    printf("*                        (       )                                         *\n");
    printf("*                       ( (  )  ) )                                        *\n");
    printf("*                       (__(__)__)                                         *\n");
    printf("*                    /\\_/\\  /\\_/\\                                      *\n");
    printf("*                   ( o   o)( o   o )                                      *\n");
    printf("*                 =(  =^=  )=  =^=  )=                                     *\n");
    printf("*                   )      ( )      (                                      *\n");
    printf("*                  (        )(       )                                     *\n");
    printf("*                 ( (  )  )( (  )  ) )                                     *\n");
    printf("*                (__(__)__) (__(__)__)                                     *\n");
    printf("*               /\\_/\\   /\\_/\\   /\\_/\\                                *\n");
    printf("*               ( o   o )( o   o ) ( o   o )                               *\n");
    printf("*              =(  =^=  )=(  =^=  )=(  =^=  )=                             *\n");
    printf("*               )      (   )      (   )     (                              *\n");
    printf("*             (        ) (        ) (       )                              *\n");
    printf("*               ( (  )  )( (  )  )( (  )  ) )                              *\n");
    printf("*              (__)(__)(__)(__)(__)(__)(__)                                *\n");
    printf("*                                                                          *\n");
    printf("****************************************************************************\n");
}

bool checkPassword() {
    char password[] = "2024";
    char inputPasword[5];
    int passwordAttempts;
    int waitTime = 3;
    
    int i;
    int j;
    for (i = 0; i < 3; i++) {
        clear_screen();
        personalScreen();
        printf("please enter password(2024):");
        fgets(inputPasword, sizeof(inputPasword), stdin);

        if (strcmp(inputPasword, password) == 0) {
            return true;
        } else {
            for (j = waitTime; j > 0; j--) {
                clear_screen();
                personalScreen();
                printf("incorrect password, please try again in %d seconds\n", j);
                sleep(1);
            }
        }
    }
    printf("you have tried 3 times, program will exit\n");
    return false;
}

void mainMenu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Enter student grades           |\n");
    printf("| b. Display student grades	    |\n");
    printf("| c. Search for student grades 	    |\n");
    printf("| d. Grade ranking                  |\n");
    printf("| e. Exit system  		    |\n");
    printf("------------------------------------\n");
}

void inputData() { //check
    if (studentCount >= MAX_STUDENT) {
        printf("you have reached the maximum number of students\n");
        return;
    }
    
    int n;
    printf("please enter the number of students:");
    while (scanf("%d", &n) != 1 || n < MIN_STUDENT || n > MAX_STUDENT) {
        printf("invalid input, please enter again:");
        while (getchar()!= '\n');
    }

    for (int i = 0; i < n; i++) {
        printf("please enter student%d name: ", i + 1);
        fflush(stdin);
        scanf("%s", student[studentCount].name);

        printf("please enter student ID: ");
        while (scanf("%d", &student[studentCount].id) != 1 || student[studentCount].id < 100000 || student[studentCount].id > 999999) {
            printf("invalid ID. please enter again:\n");
            while (getchar()!= '\n');
        }
        
        printf("please enter math score: ");
        while (scanf("%d", &student[studentCount].math) != 1 || student[studentCount].math < 0 || student[studentCount].math > 100) {
            printf("invalid score. please enter again:\n");
            while (getchar()!= '\n');
        }

        printf("please enter physics score: ");
        while (scanf("%d", &student[studentCount].physics) != 1 || student[studentCount].physics < 0 || student[studentCount].physics > 100) {
            printf("invalid score. please enter again:\n");
            while (getchar()!= '\n');
        }

        printf("please enter english score: ");
        while (scanf("%d", &student[studentCount].english) != 1 || student[studentCount].english < 0 || student[studentCount].english > 100) {
            printf("invalid score. please enter again:\n");
            while (getchar()!= '\n');
        }
        
        student[studentCount].average = (student[studentCount].math + student[studentCount].physics + student[studentCount].english) / 3.0;
        studentCount++;
    }

    printf("press any key to continue...\n");
    getch();
    clear_screen();
}

void displayData() {
    for (int i = 0; i < studentCount; i++) {
        printf("name: %s\n", student[i].name);
        printf("ID: %d\n", student[i].id);
        printf("math: %d\n", student[i].math);
        printf("physics: %d\n", student[i].physics);
        printf("english: %d\n", student[i].english);
        printf("average: %.2f\n", student[i].average);
    }

    printf("press any key to continue...\n");
    getch();
    clear_screen();
}

void searchGrade() {
    char searchName[30];
    printf("please enter student name: ");
    fflush(stdin);
    scanf("%s", searchName);

    for (int i = 0; i <= studentCount; i++) {
        if (strcmp(student[i].name, searchName) == 0) {
            printf("name: %s\n", student[i].name);
            printf("ID: %d\n", student[i].id);
            printf("math: %d\n", student[i].math);
            printf("physics: %d\n", student[i].physics);
            printf("english: %d\n", student[i].english);
            printf("average: %.2f\n", student[i].average);
            break;
        }

        if (i == studentCount) {
            printf("student not found\n");
            break;
        }
    }

    printf("press any key to continue...\n");
    getch();
    clear_screen();
}
void sort_student() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (student[j].average > student[i].average) {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }
}

void gradeRanking() {
    sort_student();
    for (int i = 0; i < studentCount; i++) {
        printf("name: %s\n", student[i].name);
        printf("ID: %d\n", student[i].id);
        printf("math: %d\n", student[i].math);
        printf("physics: %d\n", student[i].physics);
        printf("english: %d\n", student[i].english);
        printf("average: %.2f\n", student[i].average);
        printf("\n");
    }

    printf("press any key to continue...\n");
    getch();
    clear_screen();
}
