#include <stdio.h>// 標準輸入輸出庫
#include <stdlib.h>// 標準庫，包括內存分配、過程控制等
#include <conio.h>// 控制台輸入輸出
#include <stdbool.h>// 包含布爾類型支持的標頭文件，提供true和false常量以及bool類型
#include <string.h>// 字符串操作函數
#include <ctype.h>// 字符類型函數
#include <unistd.h>// Unix標準函數（如sleep等）
#include <time.h>// 時間相關函數

#define ROWS 9// 定義座位圖的行數
#define COLS 9// 定義座位圖的列數
#define BOOKED_SEATS 10// 預訂座位的數量

void clear_screen();// 清屏函數的聲明
void personalScreen();// 顯示個人信息屏幕的函數聲明
void resetSeatChart();// 重置座位圖的函數聲明
void randomBook();// 隨機預訂座位的函數聲明
void mainMenu();// 主菜單函數的聲明
void displaySeatChart();// 顯示座位圖的函數聲明
bool autoBook();// 自動預訂座位函數的聲明
bool manualBook();// 手動預訂座位函數的聲明
bool checkPassword();// 檢查密碼函數的聲明
char getInput(); // 獲取輸入函數的聲明

char seatChart[ROWS][COLS];// 座位圖的二維字符陣列(ROWS行和COLS列)
char choice;// 儲存用戶在主菜單中選擇的選項('a','b','c','d')
char input[20]; // 儲存用戶輸入的字符串(長度為20)
int row, col;// 行和列的變量
int numSeat; // 預訂座位數的變量
int mode, min = 1, max = 2;// 模式選擇和隨機數範圍變量('min'和'max'定義了隨機數生成的範圍，預設為1和2)
int row1, row2, col1, col2, col3, col4;// 儲存多個行和列的索引
char *token;// 字符串分割用的指針
char satisfaction; // 用戶滿意度的字符變量


void clear_screen() {
    system("cls"); // 使用系統命令清除屏幕
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
// 重置座位圖的函數
void resetSeatChart() {
    for (int i = 0; i < ROWS; i++) { // 外層迴圈，用來遍歷一行中的所有的行
    for (int j = 0; j < COLS; j++) { // 內層迴圈，用來遍歷每一行中的所有列
            seatChart[i][j] ='-';  // 將每個座位設置為'-'表示未預訂
        }
    }
}
// 隨機預訂座位的函數
void randomBook() { 
    srand(time(NULL)); // 用當前時間設置隨機數種子 
    for (int i = 0; i < BOOKED_SEATS; i++) { // 遍歷需要預訂的座位數
        row = rand() % ROWS; // 生成一個隨機的行索引，範圍在0到ROWS-1之間 
/*這行代碼的目的是在0和ROWS-1之間生成一個隨機數，這個數值會用來作為座位圖中的行索引(例如，如果ROWS是9，那麼rand() % ROWS的結果將會是0到8之間的隨機數)*/
        col = rand() % COLS;// 生成一個隨機的列索引，範圍在0到COLS-1之間
/*這行代碼的目的是在0和COLS-1之間生成一個隨機數，這個數值會用來作為座位圖中的列索引(例如，如果COLS是9，那麼rand() % COLS的結果將會是0到8之間的隨機數)*/
        seatChart[row][col] = '*'; // 將隨機選定的座位標記為'*'表示已預訂
    }
}

void mainMenu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats 		   |\n");
    printf("| b. Arrange for you	       	   |\n");
    printf("| c. Choose by yourself 	   |\n");
    printf("| d. Exit 			   |\n");
    printf("------------------------------------\n");
}

void displaySeatChart() {
    printf("\n  1 2 3 4 5 6 7 8 9\n");
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf(" %c", seatChart[i][j]);
        }
        printf("\n");
    }
    printf("按下任意鍵返回主選單...");
    getch();
    clear_screen();
}

bool autoBook() {
    srand(time(NULL));
    do {
        printf("how many seats do you need?\n");
        fflush(stdout);
        if (scanf("%d", &numSeat)!= 1) {
            clear_screen();
            printf("invalid input please try again\n");

            while (getchar() != '\n');
            continue;
        }

        if (numSeat < 1 || numSeat > 4) {
            clear_screen();
            printf("invalid input please try again\n");
        }
    } while (numSeat < 1 || numSeat > 4);

    do {
        bool found = false;
        if (numSeat < 4) {
            if (numSeat == 1) {
                do {
                    row1 = rand() % ROWS;
                    col1 = rand() % (COLS - numSeat + 1);
                } while (seatChart[row1][col1] == '*');
                seatChart[row1][col1] = '@';
                found = true;
            } else if (numSeat == 2) {
                do {
                    row1 = rand() % ROWS;
                    col1 = rand() % (COLS - numSeat + 1);
                    col2 = (col1 + 1) % COLS;
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*');
                seatChart[row1][col1] = '@';
                seatChart[row1][col2] = '@';
                found = true;
            } else if (numSeat == 3) {
                do {
                    row1 = rand() % ROWS;
                    col1 = rand() % (COLS - numSeat + 1);
                    col2 = (col1 + 1) % COLS;
                    col3 = (col2 + 1) % COLS;
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row1][col3] == '*');
                seatChart[row1][col1] = '@';
                seatChart[row1][col2] = '@';
                seatChart[row1][col3] = '@';
                found = true;
            }
        } else {
            mode = rand() % (max - min + 1) + 1;
            mode = mode % 2;
            if (mode == 0) { 
                do {
                    row1 = rand() % ROWS;
                    col1 = rand() % (COLS - numSeat + 1);
                    col2 = (col1 + 1) % COLS;
                    col3 = (col2 + 1) % COLS;
                    col4 = (col3 + 1) % COLS;
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row1][col3] == '*' || seatChart[row1][col4] == '*');
                seatChart[row1][col1] = '@';
                seatChart[row1][col2] = '@';
                seatChart[row1][col3] = '@';
                seatChart[row1][col4] = '@';
                found = true;
            } else { 
                do {
                    row1 = rand() % (ROWS - 1);
                    row2 = (row1 + 1) % ROWS;
                    col1 = rand() % (COLS - numSeat + 1);
                    col2 = (col1 + 1) % COLS;
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row2][col1] == '*' || seatChart[row2][col2] == '*');
                seatChart[row1][col1] = '@';
                seatChart[row1][col2] = '@';
                seatChart[row2][col1] = '@';
                seatChart[row2][col2] = '@';
                found = true;
            }
        }
        
        printf("\n  1 2 3 4 5 6 7 8 9\n");
        for (int i = ROWS - 1; i >= 0; i--) {
            printf("%d", i + 1);
                for (int j = 0; j < COLS; j++) {
                    printf(" %c", seatChart[i][j]);
            }
        printf("\n");
        }

        printf("are you satisfaction with the suggested seats? (Y/N)\n");
        fflush(stdout);
        satisfaction = getch();
        satisfaction = tolower(satisfaction);
        if (satisfaction != 'y') {
            clear_screen();
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (seatChart[i][j] == '@') {
                        seatChart[i][j] = '-';
                    }
                }
            }
        } else {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (seatChart[i][j] == '@') {
                        seatChart[i][j] = '*';
                    }
                }
            }
            printf("press enter to continue...\n");
            getch();
            clear_screen();
            break;
        }
    } while (true); 

    clear_screen();
    return 0;
}

