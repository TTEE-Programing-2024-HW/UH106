#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <stdbool.h> 
#include <string.h> 
#include <ctype.h>
#include <unistd.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define BOOKED_SEATS 10

void clear_screen();
void personalScreen();
void resetSeatChart();
void randomBook();
void mainMenu();
void displaySeatChart();
bool autoBook();
bool manualBook();
bool checkPassword();
char getInput();

char seatChart[ROWS][COLS];
char choice;
char input[20];
int row, col;
int numSeat;
int mode, min = 1, max = 2;
int row1, row2, col1, col2, col3, col4;
char *token;
char satisfaction;

void clear_screen() {
    system("cls");
}

void personalScreen() {
    printf("****************************************************************************\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
    printf("*                     Created by H1.06ªL¬L¥ì                               *\n");
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
