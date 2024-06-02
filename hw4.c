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

void clear_screen();// Declaration of function to clear screen
bool checkPassword();// Declaration of function to check password
void mainMenu();// Declaration of function to display main menu
void personalScreen();// Declaration of function to display personal screen
void inputData();// Declaration of function to input student data
void displayData();// Declaration of function to display student data
void searchGrade();// Declaration of function to search for a student's grade by name
void sort_student();// Declaration of function to sort students by their average grades
void gradeRanking();// Declaration of function to display the grade ranking
char getInput();// Declaration of function to get user input

// Structure definition for Student
typedef struct {
    char name[30];// Student's name
    int id;// Student's ID
    int math;// Math score
    int physics;// Physics score
    int english; // English score
    float average; // Average score
} Student;

Student student[MAX_STUDENT];// Array to store student information
int studentCount = 0;// Counter for number of students

// Function to clear the screen (specific to Windows)
void clear_screen() {
    system("cls");// Clear the console screen using system command
}

void personalScreen() {
    printf("****************************************************************************\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
	printf("*                     Created by H1.06�L�L��                               *\n");
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
    char inputPasword[5]; // Buffer to store user input password
    int passwordAttempts; // Variable to keep track of password attempts
    int waitTime = 3; // Wait time in seconds between attempts
    
    int i; // Loop counter for password attempts
    int j; // Loop counter for wait time
    for (i = 0; i < 3; i++) { // Allow up to 3 attempts
        clear_screen(); // Clear the screen
        personalScreen(); // Display personal screen
        printf("please enter password(2024):");
        fgets(inputPasword, sizeof(inputPasword), stdin); // Get user input

        if (strcmp(inputPasword, password) == 0) {  // Check if input matches the correct password
            return true; // If correct, return true
        } else {
            for (j = waitTime; j > 0; j--) { // Wait before allowing another attempt
                clear_screen(); // Clear the screen
                personalScreen(); // Display personal screen
                printf("incorrect password, please try again in %d seconds\n", j);
                sleep(1); // Wait for 1 second
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

void inputData() { // Check if maximum number of students is reached
    if (studentCount >= MAX_STUDENT) {
        printf("you have reached the maximum number of students\n");
        return;
    }
    
    int n;  // Variable to store number of students to be entered
    printf("please enter the number of students:");
    while (scanf("%d", &n) != 1 || n < MIN_STUDENT || n > MAX_STUDENT) {  // Validate input
        printf("invalid input, please enter again:");
        while (getchar()!= '\n'); // Clear input buffer
    }

    int i; // Loop counter for students
    for (i = 0; i < n; i++) {
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
	int i;
    for (i = 0; i < studentCount; i++) {
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
    
    int i;
    for (i = 0; i <= studentCount; i++) {
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
	int i;
	int j;
    for (i = 0; i < studentCount - 1; i++) { 
        for (j = i + 1; j < studentCount; j++) { 
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
    
    int i;
    for (i = 0; i < studentCount; i++) { 
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

char getInput() {
    char choice;
    printf("please enter your choice:");
    fflush(stdin);
    choice = getch();
    return choice;
}

int main() {
    char choice;
    if (!checkPassword()) {
        return 0;
    }

    while (true) {
        clear_screen();
        mainMenu();
        choice = getInput();
        clear_screen();

        switch (choice) {
            case 'A':
            case 'a':
                inputData();
                break;
            case 'B':
            case 'b':
                displayData();
                break;
            case 'C':
            case 'c':
                searchGrade();
                break;
            case 'D':
            case 'd':
                gradeRanking();
                break;
            case 'E':
            case 'e':
                do {
                    printf ("are you sure you want to exit? (y/n)\n");
                    choice = getInput();
                    choice = tolower(choice);
                    if (choice == 'y') {
                        printf("exiting...\n");
                        return 0;
                    } else if (choice == 'n') {
                        printf("\n");
                        break;
                    } else {
                        clear_screen();
                        printf("invalid input\n");
                    } 
                } while (choice == 'y' || choice == 'n');
                break;
            default:
                printf("invalid input\n");
        }
    }

    system("pause");
    return 0;    
}
