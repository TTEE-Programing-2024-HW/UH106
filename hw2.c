#include <stdio.h>//標準輸入輸出函式庫
#include <stdlib.h>//標準函式庫
#include <conio.h>//輸入輸出函式的定義
#include <stdbool.h>//定義 true 和 false
#include <string.h>//定義strcmp()、strcpy()字串處理函式
#include <ctype.h>//義toupper()、tolower()字符處理函式
#include <unistd.h>//定義sleep()操作系統服務的函式

void clearScreen(); //清理螢幕
void personalScreen();//個人風格畫面
bool checkPassword();//檢查密碼正確
void mainMenu();//主畫面
void drawRightTeiangle(); //畫直角三角形
void multiplication_table();//乘法表
char getInput();//取得選擇

void clearScreen() //清理螢幕
{     
    system("cls");      
} 

void personalScreen() { 
	printf("****************************************************************************\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
    printf("*                          Created by H1.06林昭伊                          *\n");
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

bool checkPassword(){ //檢查密碼是否正確
     char password[] = "2024"; //設定預設密碼
     char inputPassword[5]; //設定輸入密碼
     int passwordAttempts=3; //設定嘗試次數
     int maxAttempts = 3; //設定最大嘗試次數
     for (int i = 0; i < maxAttempts; i++)//驗證密碼
	 { 
        clearScreen();//清理螢幕
        personalScreen(); //顯示個人風格畫面
        printf("請輸入四位數字密碼（2024）:");
        fgets(inputPassword, sizeof(inputPassword), stdin);//使用 fgets 從標準輸入(stdin)讀取使用者輸入的密碼，並存儲在 inputPassword 中

        if (strcmp(inputPassword, password) == 0) { //如果輸入的密碼與預設密碼相符
            return true;//返回 true，表示密碼正確            
        } else { //如果輸入的密碼與預設密碼不相符
            clearScreen();
            personalScreen();
            printf("密碼錯誤!請重新輸入（剩餘%d次機會）\n", maxAttempts - i - 1);//提示密碼錯誤並告知使用者剩餘輸入次數
        }
    }
     
    printf("已連續輸入錯誤三次,程式即將結束\a\n");
	return false; //結束程式
}

void mainMenu() { // 主畫面
    printf("--------------------------\n");
    printf("|  a. 畫出直角三角形    |\n");
    printf("|  b. 顯示乘法表        |\n");
    printf("|  c. 結束                |\n");
    printf("--------------------------\n");
}
void drawRightTeiangle() { //畫直角三角形
    char ch;//用於存儲輸入的字符
    int i,j;//循環變量
    int n;//用於存儲三角形的行數

    do {
        printf("請輸入一個字元（a到n之間）："); //提示用戶輸入一個字符，並指定範圍為a到n之間 
        fflush(stdin); //清空緩衝區
        scanf("%c", &ch);//讀取用戶輸入的字符
        
        //如果輸入的字元是小寫的 'a' 到 'n' 或大寫的 'A' 到 'N' 
        if ((ch >= 'a' && ch <= 'n') || (ch >='A' && ch <= 'N')) {
            break; //脫離迴圈
        } else {
            clearScreen();//清除螢幕
            printf("輸入錯誤,請輸入a到n之間的字母\n\a");//提示輸入錯誤並要求重新輸入
        }
    } while (1);

    printf("三角形:\n");//輸出三角形
    if (islower(ch))//如果輸入的字元是小寫字母
	 {
        n = ch - 'a' + 1;//計算小寫字元與 'a' 的相對位置，並加 1
    } 
	else if (isupper(ch)) //如果輸入的字元是大寫字母
	{
        n = ch - 'A' + 1;//計算大寫字元與 'A' 的相對位置，並加 1
    }

    for (i = 1; i <= n; i++) { // 打印空格  
        for (j = 1; j <= n - i; j++) {
            printf(" ");//在每一行的起始位置打印空格，用於形成直角三角形的空白部分，數量隨著行數增加而減少
        
        }

        for (j = 1; j <= i; j++) { // 打印字元
            if (islower(ch))//如果輸入的字元是小寫字母
                printf("%s", ch - (i - j));//以遞減方式打印字元，形成直角三角形
            else if (isupper(ch))//如果輸入的字元是大寫字母
                printf("%s", toupper(ch) - (i - j));//以遞減方式打印字元，形成直角三角形
        }

        printf("\n");//換行，進入下一行打印
    }

    printf("按下任意鍵返回主選單..."); //返回主選單
    getch();//等待用戶輸入任意鍵
    clearScreen();// 清空螢幕
    
void multiplication_table() { //乘法表
    int num;//輸入數字 
    int i,j;//迴圈索引變數
    
    do {
        printf("請輸入一個1到9之間的數字："); //輸入一個1到9之間的數字
        fflush(stdin); //清空緩衝區
        scanf("%d", &num);//讀取用戶輸入的數字

        if (num >= 1 && num <= 9) { //如果輸入在1到9之間
            break; //脫離迴圈
        } else {
            clearScreen();//清空螢幕
            printf("輸入錯誤,請輸入1到9之間的數字\n\a");//提示輸入錯誤，並要求重新輸入
        }
    } while (1);

    printf("乘法表:\n");
    for (i = 1; i <= num; i++) { //外部迴圈控制行數，i代表乘法表的行數
        for (j = 1; j <= num; j++) { //內部迴圈控制每行的乘法表內容 
            printf("%d*%d=%d\t", i, j, i * j); //印出乘法表的每一項，格式為 i*j=i*j
        }
        printf("\n");//每印完一行乘法表內容後換行
    }

    printf("按下任意鍵返回主選單..."); //返回主選單
    getch();
    clearScreen();
}

char getInput() { //取得選擇
    char choice;//宣告用戶選擇的變數
    printf("請輸入您的選擇：");
    fflush(stdin);//清空輸入緩衝區
    choice = getch();//獲取用戶輸入的選擇
    return choice;//返回用戶輸入的選擇
}

int main() {
    char choice;//宣告用戶選擇的變數

    if (!checkPassword()) { //檢查密碼，如果錯誤則結束 
        return 0;
    }

    while (1) {
        clearScreen();//清空螢幕
        mainMenu(); //主畫面     
        choice = getInput();//獲取用戶選擇
        clearScreen();//清空螢幕準備顯示選項內容

        switch (choice) {
            case 'A': 
            case 'a':
                drawRightTeiangle();//畫直角三角形
                break;
            case 'B':
            case 'b':
                multiplication_table();//顯示乘法表
                break;
            case 'C':
            case 'c':
                do {
                    printf("Continue? (y/n):\n");//提示是否繼續
                    choice = getInput();//獲取選擇
                    choice = tolower(choice);//將選擇轉換為小寫字母

                    if (choice == 'y') { //如果選擇繼續
                        printf("\n");
                        clearScreen();//清空螢幕
                        break;//跳出循環，返回主選單
                    } else if (choice == 'n') { //如果選擇結束
                        printf("程式結束"); 
                        return 0;//結束程式
                    } else { //如果用戶輸入了無效的選項
                        clearScreen();//清空螢幕
                        printf("輸入錯誤,請輸入有效選項\n\a");//提示輸入無效
                    }
                } while (choice =='y' || choice =='n');//迴圈循環，直到用戶輸入了有效的選項
                break;//跳出迴圈 
            default:
                printf("請輸入有效選項。\n\a");//提示輸入無效
        }
    }

    system("pause");//等待用戶按下任意鍵
    return 0;//結束程式 
}

	
