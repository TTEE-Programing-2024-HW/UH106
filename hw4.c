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

