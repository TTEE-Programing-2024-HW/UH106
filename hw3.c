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
    printf("| a. Available seats 		   |\n"); // 選項：顯示可用座位
    printf("| b. Arrange for you	       	   |\n"); // 選項：系統自動為您安排座位
    printf("| c. Choose by yourself 	   |\n"); // 選項：自己選擇座位
    printf("| d. Exit 			   |\n");
    printf("------------------------------------\n");
}

void displaySeatChart() {
    printf("\n  1 2 3 4 5 6 7 8 9\n"); // 打印座位圖的列號(1-9列)
    for (int i = ROWS - 1; i >= 0; i--) { //通過一個 for 循環從底部（第 ROWS 行）到頂部（第 1 行）遍歷座位圖的每一行，行號從 ROWS 開始遞減，每次遞減 1 
        printf("%d", i + 1);//在每行的開始打印行號，行號從 1 到 ROWS
        for (int j = 0; j < COLS; j++) { //從 0 開始，直到 j 等於 COLS（列數）為止。在這個循環中，每次迭代都會增加 j 的值
            printf(" %c", seatChart[i][j]); //打印當前行（由外層循環的變量 i 表示）和當前列（由內層循環的變量 j 表示）位置的座位狀態
        }
        printf("\n");// 在每行結束時換行
    }
    printf("按下任意鍵返回主選單...");// 提示用戶按任意鍵返回主菜單
    getch();// 等待用戶輸入
    clear_screen();// 清屏
}

bool autoBook() {
    srand(time(NULL));// 用當前時間作為隨機數生成器的種子
    do {
        printf("how many seats do you need?\n");// 提示用戶輸入需要的座位數
        fflush(stdout);// 刷新輸出緩衝區
        if (scanf("%d", &numSeat)!= 1) { // 讀取座位數並檢查輸入是否有效
            clear_screen();// 如果輸入無效，清屏
            printf("invalid input please try again\n");// 通知用戶輸入無效

            while (getchar() != '\n');// 清除輸入緩衝區
            continue;// 重新開始循環
        }

        if (numSeat < 1 || numSeat > 4) { // 如果超出範圍(小於1以下 或大於4以上) 
            clear_screen();// 清屏
            printf("invalid input please try again\n");// 通知用戶輸入無效
        }
    } while (numSeat < 1 || numSeat > 4);// 重複直到輸入有效座位數

    do {
        bool found = false;// 標誌是否找到有效的座位安排
        if (numSeat < 4) { // 如如果需要的座位數小於4，進入這段程式碼
            if (numSeat == 1) { // 如果只需要一個座位
                do {
                    row1 = rand() % ROWS; //使用隨機數生成器隨機選擇一行
                    col1 = rand() % (COLS - numSeat + 1);// 隨機生成列
                } while (seatChart[row1][col1] == '*');// 如果座位已被預訂，重複此過程
                seatChart[row1][col1] = '@';// 暫時標記該座位已預訂
                found = true;// 標記找到有效的座位安排
            } else if (numSeat == 2) { // 如果需要兩個座位
                do {
                    row1 = rand() % ROWS;//使用隨機數生成器隨機選擇一行
                    col1 = rand() % (COLS - numSeat + 1);// 隨機生成列號，確保有足夠的連續座位
                    col2 = (col1 + 1) % COLS;// 計算第二個座位的列號，確保它是連續的
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*');// 如果任何一個座位已被預訂，重複此過程
                seatChart[row1][col1] = '@';// 暫時標記第一個座位已預訂
                seatChart[row1][col2] = '@'; // 暫時標記第二個座位已預訂
                found = true;// 標記找到有效的座位安排
            } else if (numSeat == 3) {// 如果需要三個座位
                do {
                    row1 = rand() % ROWS;// 隨機生成行號
                    col1 = rand() % (COLS - numSeat + 1);// 隨機生成列號，確保有足夠的連續座位
                    col2 = (col1 + 1) % COLS;// 計算第二個座位的列號，確保它是連續的 
                    col3 = (col2 + 1) % COLS;// 計算第三個座位的列號，確保它是連續的
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row1][col3] == '*');// 如果任何一個座位已被預訂，重複此過程
                seatChart[row1][col1] = '@';// 暫時標記第一個座位已預訂
                seatChart[row1][col2] = '@';// 暫時標記第二個座位已預訂
                seatChart[row1][col3] = '@';// 暫時標記第三個座位已預訂
                found = true;// 標記找到有效的座位安排
            }
        } else {// 否則，如果需要的座位數為四個
            mode = rand() % (max - min + 1) + 1;//生成一個介於 min 和 max 之間的隨機整數
            mode = mode % 2;//將先前生成的隨機數取餘數除以 2，以獲得一個範圍在 0 到 1 之間的隨機數
            if (mode == 0) { // 如果模式為0，表示選擇連續四個座位
                do {
                    row1 = rand() % ROWS;// 隨機生成行
                    col1 = rand() % (COLS - numSeat + 1);// 隨機生成列號，確保有足夠的連續座位
                    col2 = (col1 + 1) % COLS;// 計算第二個座位的列號，確保它是連續的
                    col3 = (col2 + 1) % COLS;// 計算第三個座位的列號，確保它是連續的
                    col4 = (col3 + 1) % COLS;// 計算第四個座位的列號，確保它是連續的
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row1][col3] == '*' || seatChart[row1][col4] == '*');// 如果任何一個座位已被預訂，重複此過程
                seatChart[row1][col1] = '@';// 標記第一個座位已預訂
                seatChart[row1][col2] = '@';// 標記第二個座位已預訂
                seatChart[row1][col3] = '@';// 標記第三個座位已預訂
                seatChart[row1][col4] = '@';// 標記第四個座位已預訂
                found = true;// 標記找到有效的座位安排
            } else { // 否則，選擇2+2 座位模式
                do {
                    row1 = rand() % (ROWS - 1);// 隨機生成第一行
                    row2 = (row1 + 1) % ROWS;// 計算第二行號，確保它是連續的
                    col1 = rand() % (COLS - numSeat + 1);// 隨機生成列號，確保有足夠的連續座位
                    col2 = (col1 + 1) % COLS;// 計算第二個座位的列號，確保它是連續的
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row2][col1] == '*' || seatChart[row2][col2] == '*');// 如果任何一個座位已被預訂，重複此過程
                seatChart[row1][col1] = '@';// 標記第一個座位已預訂
                seatChart[row1][col2] = '@';// 標記第二個座位已預訂
                seatChart[row2][col1] = '@';// 標記第三個座位已預訂
                seatChart[row2][col2] = '@';// 標記第四個座位已預訂
                found = true;// 標記找到有效的座位安排
            }
        }
        
        printf("\n  1 2 3 4 5 6 7 8 9\n");// 打印列號(1-9)
        for (int i = ROWS - 1; i >= 0; i--) {//該迴圈從座位圖的最後一行開始向上遍歷。 ROWS - 1 表示從座位圖的最後一行開始
            printf("%d", i + 1);// 打印行號
                for (int j = 0; j < COLS; j++) {//從該行的第一個座位開始，當計數器 j 小於列數時，迴圈繼續執行
                    printf(" %c", seatChart[i][j]);//表示座位圖中第 i 行、第 j 列的座位狀態
            }
        printf("\n");// 在每行結束時換行
        }

        printf("are you satisfaction with the suggested seats? (Y/N)\n");// 顯示座位建議是否滿意
        fflush(stdout);// 刷新輸出緩衝區
        satisfaction = getch();// 獲取用戶滿意度
        satisfaction = tolower(satisfaction);// 將輸入轉換為小寫
        if (satisfaction != 'y') { // 如果不滿意
            clear_screen();// 清空螢幕
            for (int i = 0; i < ROWS; i++) {// 遍歷每一行
                for (int j = 0; j < COLS; j++) {// 遍歷每一列
                    if (seatChart[i][j] == '@') {// 如果座位已預訂
                        seatChart[i][j] = '-';// 將座位狀態設置為空閒
                    }
                }
            }
        } else {// 如果滿意
            for (int i = 0; i < ROWS; i++) { // 遍歷每一行
                for (int j = 0; j < COLS; j++) { // 遍歷每一列
                    if (seatChart[i][j] == '@') {// 如果座位已預訂
                     seatChart[i][j] = '*';// 將座位狀態設置為已預訂
					}
                }
            }
            printf("press enter to continue...\n");// 提示用戶按 Enter 鍵繼續
            getch();// 等待用戶按鍵
            clear_screen();// 清空螢幕
            break;// 跳出迴圈
        }
    } while (true); // 無限迴圈直到用戶滿意

    clear_screen();// 清空螢幕
    return 0;// 返回函數值
}

bool manualBook() {
    do {
        printf("please enter seat you want to book\n");
        fgets(input, sizeof(input), stdin);
        token = strtok(input, "-");
        if (token == NULL) {
            printf("invalid input please try again\n");
            continue;
        }
        row = atoi(token) - 1;
        token = strtok(NULL, "-");
        if (token == NULL) {
            printf("invalid input please try again\n");
            continue;
        }
        col = atoi(token) - 1;
        if (row < 0 || row > ROWS || col < 0 || col > COLS) {
            printf("invalid input please try again\n");
            continue;
        }
        if (seatChart[row][col] == '*') {
            printf("this seat is already booked\n");
            continue;
        }
        break;
    } while (true);

    seatChart[row][col] = '@';
    clear_screen();
    printf("\n  1 2 3 4 5 6 7 8 9\n");
        for (int i = ROWS - 1; i >= 0; i--) {
            printf("%d", i + 1);
            for (int j = 0; j < COLS; j++) {
                printf(" %c", seatChart[i][j]);
            }
        printf("\n");
        }

    printf("press enter to continue...\n");
    getch();
    clear_screen();
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seatChart[i][j] == '@') {
                seatChart[i][j] = '*';
            }
        }
    }

    return true;
}

