#include <stdio.h>// Standard Input Output library
#include <stdlib.h>// Standard library, includes memory allocation, process control, etc.
#include <conio.h>// // Console Input Output (specific to Windows)
#include <stdbool.h>// Boolean type support
#include <string.h>// String manipulation functions
#include <ctype.h>// Character type functions
#include <unistd.h>// Unix standard functions 
#include <time.h>// Time related functions

#define ROWS 9// Define the number of rows in the seat chart
#define COLS 9// Define the number of columns in the seat chart
#define BOOKED_SEATS 10// Number of seats to be booked

void clear_screen();// Declaration of function to clear screen
void personalScreen();// Declaration of function to display personal screen
void resetSeatChart();// Declaration of function to reset seat chart
void randomBook();// Declaration of function to book seats randomly
void mainMenu();// Declaration of function to display main menu
void displaySeatChart();// Declaration of function to display seat chart
bool autoBook();// Declaration of function to automatically book seats
bool manualBook();// Declaration of function to manually book seats
bool checkPassword();// Declaration of function to check password
char getInput(); // Declaration of function to get user input

char seatChart[ROWS][COLS];// 2D character array to represent the seat chart (ROWS rows and COLS columns)
char choice;// Character to store user's choice('a','b','c','d')
char input[20]; // String to store user's input(length:20) 
int row, col;// Variables for row and column
int numSeat; // Variable for number of seats to be booked
int mode, min = 1, max = 2;// Variables for the mode selection and random number range ('min' and 'max' define the range of random number generation, default is 1 and 2)
int row1, row2, col1, col2, col3, col4;// Variables to store multiple row and column indices
char *token;// Pointer for string tokenization
char satisfaction; // Character variable for user's satisfaction

// Define function to clear screen
void clear_screen() {
    system("cls");  // Use system command to clear screen (specific to Windows)
}

void personalScreen() {
    printf("****************************************************************************\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
    printf("*                     Created by H1.06林昭伊                               *\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
    printf("*                  _________                    _________                  *\n");
    printf("*                 /_________\\__________________/_________\\                 *\n");
    printf("*                /                                        \\                *\n");
    printf("*               /   _____          o     o            Y    \\               *\n");
    printf("*              /   |     |            0             X   A   \\              *\n");
    printf("*             /    |_____| _                          A      \\             *\n");
    printf("*            /          __| |__             _____             \\            *\n");
    printf("*           /          |__   __|           |     |             \\           *\n");
    printf("*          /              |_|              |_____|              \\          *\n");
    printf("*         /        ______________________________________        \\         *\n");
    printf("*        /        /                                      \\        \\        *\n");
    printf("*       /        /                                        \\        \\       *\n");
    printf("*      /        /                                          \\        \\      *\n");
    printf("*     /        /                                            \\        \\     *\n");
    printf("*    /        /                                              \\        \\    *\n");
    printf("*   |________/                                                \\________|   *\n");
    printf("****************************************************************************\n");
}
// Function to reset the seat chart
void resetSeatChart() {
    int i, j;
    for (i = 0; i < ROWS; i++) { // // Outer loop to iterate through all the rows
        for (j = 0; j < COLS; j++) { // Inner loop to iterate through all the columns in each row
            seatChart[i][j] ='-';  // Set each seat to '-' to indicate it is not booked
        }
    }
}

// Function to randomly book seats
void randomBook() { 
    srand(time(NULL)); // Set random seed using current time
    for (int i = 0; i < BOOKED_SEATS; i++) { // Iterate through the number of seats to be booked
        row = rand() % ROWS; // Generate a random row index within the range of 0 to ROWS-1
    /*The purpose of this line of code is to generate a random number between 0 and ROWS-1, and this value will be used as the row index in the seat 
	chart (for example, if ROWS is 9, the result of rand() % ROWS will be a random number between 0 and 8)*/
        col = rand() % COLS;// Generate a random column index within the range of 0 to COLS-1
    /*The purpose of this line of code is to generate a random number between 0 and COLS-1, and this value will be used as the column index in the seat 
	chart (for example, if COLS is 9, the result of rand() % COLS will be a random number between 0 and 8)*/
        seatChart[row][col] = '*'; // Mark the randomly selected seat as '*' to indicate it is booked
    }
}

void mainMenu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats 		   |\n"); // Display option a: View available seats
    printf("| b. Arrange for you	       	   |\n"); // Display option b: Arrange seats for you
    printf("| c. Choose by yourself 	   |\n"); // Display option c: Choose seats yourself
    printf("| d. Exit 			   |\n"); // Display option d: Exit
    printf("------------------------------------\n");
}
// Function to display the seat chart
void displaySeatChart() {
    printf("\n  1 2 3 4 5 6 7 8 9\n"); // Print the column numbers (1-9)
    for (int i = ROWS - 1; i >= 0; i--) { // Iterate through the seat chart from the bottom (row ROWS) to the top (row 1), decrementing the row number by 1 each iteration
        printf("%d", i + 1);// Print the row number, starting from 1 to ROWS
        for (int j = 0; j < COLS; j++) { // Iterate from 0 to COLS-1 (the column index)
            printf(" %c", seatChart[i][j]);// Print the status of the seat at the current row (from the outer loop variable i) and current column (from the inner loop variable j)
        }
        printf("\n");// Move to the next line after each row
    }
    printf("Press any key to return to the main menu...");// Prompt the user to press any key to return to the main menu
    getch();// Wait for user input
    clear_screen();// Clear the screen
}
// Function to automatically book seats
bool autoBook() {
    srand(time(NULL));// Set random seed using current time
    
    // Main loop to get the number of seats from the user
    do {
        printf("how many seats do you need?\n");// Prompt the user to enter the number of seats needed
        fflush(stdout);// Flush the output buffer
        if (scanf("%d", &numSeat)!= 1) { // Read number of seats and check if input is valid
            clear_screen();// Clear the screen
            printf("invalid input please try again\n");// Notify the user that the input is invalid

            while (getchar() != '\n');// Clear the input buffer
            continue;// Continue to the next iteration of the loop
        }
        
        if (numSeat < 1 || numSeat > 4) { // If the number of seats is out of range (less than 1 or greater than 4)  
            clear_screen();// Clear the screen
            printf("invalid input please try again\n");// Notify the user that the input is invalid
        }
    } while (numSeat < 1 || numSeat > 4);// Repeat until a valid number of seats is entered


    do {
        bool found = false;// Flag to indicate whether a valid seat arrangement has been found
        if (numSeat < 4) { // If the number of seats needed is less than 4, enter this code block
            if (numSeat == 1) { // If only one seat is needed
                do {
                    row1 = rand() % ROWS;// Use the random number generator to randomly select a row
                    col1 = rand() % (COLS - numSeat + 1);// Randomly generate a column
                } while (seatChart[row1][col1] == '*');// If the seat is already booked, repeat this process
                seatChart[row1][col1] = '@';// Temporarily mark this seat as booked
                found = true;// Mark that a valid seat arrangement has been found
            } else if (numSeat == 2) { // If two seats are needed
                do {
                    row1 = rand() % ROWS;// Use the random number generator to randomly select a row
                    col1 = rand() % (COLS - numSeat + 1);// Randomly generate a column number, ensuring there are enough consecutive seats
                    col2 = (col1 + 1) % COLS;// Calculate the column number for the second seat, ensuring it is consecutive
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*');// If either seat is already booked, repeat this process
                seatChart[row1][col1] = '@';// Temporarily mark the first seat as booked
                seatChart[row1][col2] = '@'; // Temporarily mark the second seat as booked
                found = true;// Mark that a valid seat arrangement has been found
            } else if (numSeat == 3) {// If three seats are needed
                do {
                    row1 = rand() % ROWS;// Randomly generate a row number
                    col1 = rand() % (COLS - numSeat + 1);// Randomly generate a column number, ensuring there are enough consecutive seats
                    col2 = (col1 + 1) % COLS;// Calculate the column number for the second seat, ensuring it is consecutive 
                    col3 = (col2 + 1) % COLS;// Calculate the column number for the third seat, ensuring it is consecutive
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row1][col3] == '*');// If any of the seats are already booked, repeat this process
                seatChart[row1][col1] = '@';// Temporarily mark the first seat as booked
                seatChart[row1][col2] = '@';// Temporarily mark the second seat as booked
                seatChart[row1][col3] = '@';// Temporarily mark the third seat as booked
                found = true;// Mark that a valid seat arrangement has been found
            }
        } else {// Otherwise, if the number of seats needed is four
            mode = rand() % (max - min + 1) + 1;//Generate a random integer between min and max
            mode = mode % 2;// Take the remainder of the previously generated random number divided by 2 to get a random number between 0 and 1
            if (mode == 0) { // If the mode is 0, it means choosing 4 consecutive seats
                do {
                    row1 = rand() % ROWS;// Randomly generate a row
                    col1 = rand() % (COLS - numSeat + 1);// Randomly generate a column number, ensuring there are enough 
                    col2 = (col1 + 1) % COLS;// Calculate the column number for the second seat, ensuring it is consecutive
                    col3 = (col2 + 1) % COLS;// Calculate the column number for the third seat, ensuring it is consecutive
                    col4 = (col3 + 1) % COLS;// Calculate the column number for the fourth seat, ensuring it is consecutive
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row1][col3] == '*' || seatChart[row1][col4] == '*');// If any of the seats are already booked, repeat this process
                seatChart[row1][col1] = '@';// Mark the first seat as booked
                seatChart[row1][col2] = '@';// Mark the second seat as booked
                seatChart[row1][col3] = '@';// Mark the third seat as booked
                seatChart[row1][col4] = '@';// Mark the fourth seat as booked
                found = true;// Mark that a valid seat arrangement has been found
            } else { // Otherwise, choose the 2+2 seat mode
                do {
                    row1 = rand() % (ROWS - 1);// Randomly generate the first row
                    row2 = (row1 + 1) % ROWS;// Calculate the second row number, ensuring it is consecutive
                    col1 = rand() % (COLS - numSeat + 1);// Randomly generate a column number, ensuring there are enough consecutive seats
                    col2 = (col1 + 1) % COLS;// Calculate the column number for the second seat, ensuring it is consecutive
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row2][col1] == '*' || seatChart[row2][col2] == '*');// If any of the seats are already booked, repeat this process
                seatChart[row1][col1] = '@';// Mark the first seat as booked
                seatChart[row1][col2] = '@';// Mark the second seat as booked
                seatChart[row2][col1] = '@';// Mark the third seat as booked
                seatChart[row2][col2] = '@';// Mark the fourth seat as booked
                found = true;// Mark that a valid seat arrangement has been found
            }
        }
        
        printf("\n  1 2 3 4 5 6 7 8 9\n");// Print the column numbers (1-9)
        for (int i = ROWS - 1; i >= 0; i--) {//This loop starts from the last row of the seat chart and iterates upwards. ROWS - 1 means it starts from the last row of the seat chart
            printf("%d", i + 1);// Print the row number
                for (int j = 0; j < COLS; j++) {// Starting from the first seat in the row, the loop continues as long as the counter j is less than the number of columns
                    printf(" %c", seatChart[i][j]);// Represents the state of the seat at row i, column j in the seat chart
            }
        printf("\n");// Move to the next line after each row
        }

        printf("are you satisfaction with the suggested seats? (Y/N)\n");// Display whether the user is satisfied with the suggested seats
        fflush(stdout);// Flush the output buffer
        satisfaction = getch();// Get the user's satisfaction level
        satisfaction = tolower(satisfaction);// Convert the input to lowercase
        if (satisfaction != 'y') { // If not satisfied
            clear_screen();// Clear the screen
            for (int i = 0; i < ROWS; i++) {// Iterate through each row
                for (int j = 0; j < COLS; j++) {// Iterate through each column
                    if (seatChart[i][j] == '@') {// If the seat is booked
                        seatChart[i][j] = '-';// Set the seat status to unbooked
                    }
                }
            }
        } else {// If satisfied
            for (int i = 0; i < ROWS; i++) { // Iterate through each row
                for (int j = 0; j < COLS; j++) { // Iterate through each column
                    if (seatChart[i][j] == '@') {// If the seat is booked
                     seatChart[i][j] = '*';// Set the seat status to booked
					}
                }
            }
            printf("press enter to continue...\n");// Prompt the user to press Enter to continue
            getch();// Wait for the user to press a key
            clear_screen();// Clear the screen
            break;// Break out of the loop
        }
    } while (true); // Infinite loop until the user is satisfied

    clear_screen();// Clear the screen
    return 0;// Return the function value
}

bool manualBook() {
    do {
        printf("please enter seat you want to book\n");// Prompt the user to enter the seat they want to book
        fgets(input, sizeof(input), stdin);// Read the user input
        token = strtok(input, "-");// Tokenize the input by the "-" character
        if (token == NULL) { // If the token is NULL, the input is invalid
            printf("invalid input please try again\n");// Notify the user that the input is invalid
            continue;// Continue to the next iteration of the loop
        }
        row = atoi(token) - 1;// Convert the first token to an integer and subtract 1 to get the row index
        token = strtok(NULL, "-");// Get the next token
        if (token == NULL) { // If the token is NULL, the input is invalid
            printf("invalid input please try again\n");// Notify the user that the input is invalid
            continue;// Continue to the next iteration of the loop
        }
        col = atoi(token) - 1;// Convert the second token to an integer and subtract 1 to get the column index
        if (row < 0 || row > ROWS || col < 0 || col > COLS) { // If the row or column index is out of bounds
            printf("invalid input please try again\n");// Notify the user that the input is invalid
            continue;// Continue to the next iteration of the loop
        }
        if (seatChart[row][col] == '*') { // If the selected seat is already booked
            printf("this seat is already booked\n");// Notify the user that the seat is already booked
            continue;// Continue to the next iteration of the loop
        }
        break;// Exit the loop since a valid seat has been selected
    } while (true);// Infinite loop

    seatChart[row][col] = '@';// Mark the selected seat as booked
    clear_screen();// Clear the screen
    printf("\n  1 2 3 4 5 6 7 8 9\n");// Print the column numbers (1-9)
        for (int i = ROWS - 1; i >= 0; i--) {// Iterate through the seat chart from the bottom (row ROWS) to the top (row 1)
            printf("%d", i + 1);// Print the row number
            for (int j = 0; j < COLS; j++) {// Iterate through the columns
                printf(" %c", seatChart[i][j]);// Print the status of the seat at the current row and column
            }
        printf("\n");// Move to the next line after each row
        }

    printf("press enter to continue...\n");// Prompt the user to press Enter to continue
    getch();// Wait for the user to press a key
    clear_screen();// Clear the screen
    for (int i = 0; i < ROWS; i++) {// Iterate through each row
        for (int j = 0; j < COLS; j++) {// Iterate through each column
            if (seatChart[i][j] == '@') {// If the seat is marked as booked
                seatChart[i][j] = '*';// Set the seat status to booked
            }
        }
    }

    return true;// Return true to indicate that a seat has been booked
}

bool checkPassword() {
    char password[] = "2024";// The correct password
    char inputPasword[5];// The password entered by the user
    int passwordAttempts;// The number of password attempts
    int waitTime = 3;// The wait time between incorrect password attempts

    for (int i = 0; i < 3; i++) { // Allow 3 password attempts
        clear_screen();// Clear the screen
        personalScreen();// Display the personal screen
        printf("please enter password(2024):\n");// Prompt the user to enter the password
        fgets(inputPasword, sizeof(inputPasword), stdin);// Read the user's input

        if (strcmp(inputPasword, password) == 0) {// If the entered password matches the correct password
            return true;// Return true to indicate successful login
        } else { // If the entered password is incorrect
            for (int j = waitTime; j > 0; j--) { // Wait for the specified time
                clear_screen();// Clear the screen
                personalScreen();// Display the personal screen
                printf("incorrect password, please try again in %d seconds\n", j);// Inform the user about the wait time
                sleep(1);// Wait for 1 second
            }
        }
    }
    printf("you have tried 3 times, program will exit\n");// Inform the user that the maximum number of attempts has been reached
    return false;// Return false to indicate failed login
}

char getInput() {
    char choice;// The user's choice
    printf("please enter your choice:\n");// Prompt the user to enter their choice
    fflush(stdin);// Flush the input buffer
    choice = getch();// Get the user's input (a single character)
    return choice;// Return the user's choice
}

int main() {
    if (!checkPassword()) {// If the password check fails
        return 0;// Exit the program
    }

    resetSeatChart();// Reset the seat chart
    randomBook();// Randomly book seats

    while (true) {// Infinite loop
        clear_screen();// Clear the screen
        mainMenu();// Display the main menu
        choice = getInput();// Get the user's choice
        clear_screen();// Clear the screen

        switch (choice) {// Handle the user's choice
            case 'A':
            case 'a':
                displaySeatChart();// Display the seat chart
                break;
            case 'B':
            case 'b':
                autoBook();// Automatically book seats
                break;
            case 'C':
            case 'c':
                manualBook();// Manually book seats
                break;
            case 'D':
            case 'd':
                do { // Confirm exit
                    printf("are you sure you want to exit? (Y/N)\n");// Prompt the user to confirm exit
                    choice = getInput();// Get the user's choice
                    choice = tolower(choice);// Convert the choice to lowercase

                    if (choice == 'y') { // If the user confirms exit
                        printf("confirm exit\n");// Inform the user that the program is exiting
                        return 0;// Exit the program
                    } else if (choice == 'n') {// If the user doesn't want to exit
                        printf("\n");// Print a newline
                        clear_screen();// Clear the screen
                        break;// Break out of the inner loop
                    } else {// If the input is invalid
                        clear_screen();// Clear the screen
                        printf("invalid input please try again\n");// Notify the user of the invalid input
                    }
                } while (choice == 'y' || choice == 'n');// Continue the loop until a valid choice is made
                break;
            default:// If the input is invalid
                printf("invalid input please try again\n\a");// Notify the user of the invalid input
        }
    }

    system("pause");// Pause the program until the user presses a key
    return 0;// Exit the program

}

/*這次的作業3就不像上次的作業2那樣的慌張，對於GitHub基本的設定游刃有餘，以及add、commit、push都相對前一次來說要簡單，而且在助教的教導下我也會git除錯了!
原本當十名名助教幫我用touch hw3.c了但是後來git add hw3.c上去後再輸入git status後卻顯示不出來，當下第一反應就是...問助教，但問了之後我就在自己重新定義一次並上網自己找
debug的方法，沒想到就可以了，要不是之前看助教做過一遍，我也沒辦法除錯出來，還是只會一昧的麻煩助教很感謝助教的磨練哈哈，在成設實驗時，助教說他教我們已經算溫柔的了在往
上大家都是直接的，聽完後真的覺得我們助教算溫柔了...謝謝助教耐心一地步一步教我們，雖然我們老是說你很兇，但是布匈的話我們就部會很認真地去對待成設了，我會繼續努力寫出之
後HW4的!*/ 
