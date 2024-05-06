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


