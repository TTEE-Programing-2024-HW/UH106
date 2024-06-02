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
	printf("*                     Created by H1.06林昭伊                               *\n");
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
    for (i = 0; i < n; i++) {  // Loop to enter data for each student
        printf("please enter student%d name: ", i + 1);
        fflush(stdin); // Clear input buffer
        scanf("%s", student[studentCount].name);

        printf("please enter student ID: ");
        while (scanf("%d", &student[studentCount].id) != 1 || student[studentCount].id < 100000 || student[studentCount].id > 999999) { // Validate ID
            printf("invalid ID. please enter again:\n");
            while (getchar()!= '\n'); // Clear input buffer
        }
        
        printf("please enter math score: ");
        while (scanf("%d", &student[studentCount].math) != 1 || student[studentCount].math < 0 || student[studentCount].math > 100) {  // Validate score
            printf("invalid score. please enter again:\n");
            while (getchar()!= '\n');  // Clear input buffer
        }

        printf("please enter physics score: ");
        while (scanf("%d", &student[studentCount].physics) != 1 || student[studentCount].physics < 0 || student[studentCount].physics > 100) { // Validate score
            printf("invalid score. please enter again:\n");
            while (getchar()!= '\n'); // Clear input buffer
        }

        printf("please enter english score: ");
        while (scanf("%d", &student[studentCount].english) != 1 || student[studentCount].english < 0 || student[studentCount].english > 100) { // Validate score
            printf("invalid score. please enter again:\n");
            while (getchar()!= '\n'); // Clear input buffer
        }
        
        student[studentCount].average = (student[studentCount].math + student[studentCount].physics + student[studentCount].english) / 3.0;  // Calculate average score
        studentCount++; // Increment student count
    }

    printf("press any key to continue...\n");
    getch(); // Wait for user input
    clear_screen(); // Clear screen
}

void displayData() {
	int i; // Loop counter for students
    for (i = 0; i < studentCount; i++) {// Loop through all students
        printf("name: %s\n", student[i].name); // Display student name
        printf("ID: %d\n", student[i].id); // Display student ID
        printf("math: %d\n", student[i].math);  // Display math score
        printf("physics: %d\n", student[i].physics); // Display physics score
        printf("english: %d\n", student[i].english); // Display English score
        printf("average: %.2f\n", student[i].average);// Display average score
    }

    printf("press any key to continue...\n");
    getch(); // Wait for user input
    clear_screen(); // Wait for user input
}

void searchGrade() {
    char searchName[30]; // Buffer to store name to search
    printf("please enter student name: ");
    fflush(stdin); // Clear input buffer
    scanf("%s", searchName); // Get student name
    
    int i; // Loop counter for students
    for (i = 0; i <= studentCount; i++) { // Loop through all students
        if (strcmp(student[i].name, searchName) == 0) { // Check if name matches
            printf("name: %s\n", student[i].name); // Display student name
            printf("ID: %d\n", student[i].id); // Display student ID
            printf("math: %d\n", student[i].math); // Display math score
            printf("physics: %d\n", student[i].physics); // Display physics score
            printf("english: %d\n", student[i].english); // Display English score
            printf("average: %.2f\n", student[i].average); // Display average score
            break;
        }

        if (i == studentCount) { // If student not found
            printf("student not found\n"); // Inform user
            break; // Exit loop
        }
    }

    printf("press any key to continue...\n");
    getch(); // Wait for user input
    clear_screen(); // Clear screen
}

void sort_student() {
	int i; // Loop counter for outer loop
	int j; // Loop counter for inner loop
    for (i = 0; i < studentCount - 1; i++) {  // Outer loop for bubble sort
        for (j = i + 1; j < studentCount; j++) { // Inner loop for bubble sort
            if (student[j].average > student[i].average) { // Compare average scores
                Student temp = student[i]; // Swap students
                student[i] = student[j];
                student[j] = temp;
            } 
        }
    }
}

void gradeRanking() { 
    sort_student(); // Sort students by average score
    
    int i; // Loop counter for students
    for (i = 0; i < studentCount; i++) { // Loop through all students
        printf("name: %s\n", student[i].name); // Display student name
        printf("ID: %d\n", student[i].id);  // Display student ID
        printf("math: %d\n", student[i].math); // Display math score
        printf("physics: %d\n", student[i].physics); // Display physics score
        printf("english: %d\n", student[i].english); // Display English score
        printf("average: %.2f\n", student[i].average); // Display average score
        printf("\n"); // New line for separation
    }

    printf("press any key to continue...\n");
    getch(); // Wait for user input
    clear_screen(); // Clear screen
}

char getInput() {
    char choice; // Variable to store user choice
    printf("please enter your choice:"); 
    fflush(stdin); // Clear input buffer
    choice = getch(); // Get user input without echoing it to the console
    return choice; // Return user input
}

int main() {
    char choice; // Variable to store user menu choice
    if (!checkPassword()) { // Check if the password is correct
        return 0; // Exit program if password is incorrect
    }

    while (true) { // Infinite loop for the main menu
        clear_screen(); // Clear the screen
        mainMenu(); // Display the main menu
        choice = getInput(); // Get user choice
        clear_screen(); // Clear the screen

        switch (choice) { // Handle user choice
            case 'A': // Fallthrough to handle both 'A' and 'a'
            case 'a':
                inputData(); // Call function to input data
                break;
            case 'B': // Fallthrough to handle both 'B' and 'b'
            case 'b':
                displayData(); // Call function to display data
                break;
            case 'C': // Fallthrough to handle both 'C' and 'c'
            case 'c':
                searchGrade();// Call function to search for a grade
                break;
            case 'D': // Fallthrough to handle both 'D' and 'd'
            case 'd':
                gradeRanking(); // Call function to display grade ranking
                break;
            case 'E': // Fallthrough to handle both 'E' and 'e'
            case 'e':
                do {
                    printf ("are you sure you want to exit? (y/n)\n");
                    choice = getInput(); // Get user input
                    choice = tolower(choice); // Convert input to lowercase
                    if (choice == 'y') { // If user confirms exit
                        printf("exiting...\n");
                        return 0; // Exit program
                    } else if (choice == 'n') { // If user cancels exit
                        printf("\n");
                        break; // Break out of confirmation loop
                    } else { // If user input is invalid
                        clear_screen(); // Clear the screen
                        printf("invalid input\n");
                    } 
                } while (choice == 'y' || choice == 'n'); // Loop until valid input
                break;
            default:
                printf("invalid input\n");
        }
    }

    system("pause");
    return 0;    
}

/*這次老師只給我們差不多兩個禮拜的時間完成作業，可能是因為和之前的作業還挺相似的所以做得挺輕鬆的，除了C++外，GitHub我是越來越熟練
了，前幾次做作業時，只要是遇到bug，commit或者push不上去時，立刻就問助教，但我現在會自己上網輸入關鍵字找尋如何debug，除此之外我還會
用bash的touch自動新增一個.c檔案，讓我越來越有成就感了，希望到時候彈性教學的作業我能只靠自己的能力debug。*/ 
