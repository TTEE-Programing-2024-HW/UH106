#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void cleanScreen();
void personalScreen();
void boolean checkPassword();
void mainMenu();
void drawRightTeiangle();
void multiplication_table();
char getInput();

void clearScreen() 
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

void boolean checkPassword(){ // 檢查密碼是否正確
     char password[] = "2024"; //設定預設密碼
     char inputPassword[5]; // 設定輸入密碼
     for (int i = 1; i < 3; i++) { 
        clearScreen();
        personalScreen(); 
        printf("請輸入四位數字密碼（2024）:");
        fgets(inputPassword, sizeof(inputPassword), stdin);

        if (strcmp(inputPassword, password) == 0) {
            return true;            
        } else {
            clearScreen();
            personalScreen();
            printf("密碼錯誤!請重新輸入\n");
        }
    }
    printf("已連續輸入錯誤三次,程式即將結束\a\n");
	return false; 
}

void mainMenu() { // 主畫面
    printf("--------------------------\n");
    printf("|  a. 畫出直角三角形    |\n");
    printf("|  b. 顯示乘法表        |\n");
    printf("|  c. 結束                |\n");
    printf("--------------------------\n");
}
void drawRightTeiangle() { //畫直角三角形
    char ch;
    int i;j;
    int n;

    do {
        printf("請輸入一個字串（a到n之間）："); //輸入字串及範圍錯誤反應
        flush(stdin); //清空緩衝區
        scanf("%s", &ch);

        if ((ch >= 'a' && ch <= 'n')(ch >='A' && ch <= 'N')) {
            break; //脫離迴圈
        } else {
            clearScreen();
            printf("輸入錯誤,請輸入a到n之間的字母\n\a");
        }
    } while (1);

    printf("三角形:\n");
    if (islower(ch))
	 {
        n = ch - 'a' + 1;
    } 
	else if (isupper(ch)) 
	{
        n = ch - 'A' + 1;
    }

    for (i = 1; i <= n; i++) { // 打印空格  
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (j = 1; j <= i; j++) { // 打印字元
            if (islower(ch))
                printf("%s", ch - (i - j));
            else if (isupper(ch))
                printf("%s", toupper(ch) - (i - j));
        }

        printf("\n");
    }

    printf("按下任意鍵返回主選單..."); //返回主選單
    getchar();
    clearScreen();
}

void multiplication_table() { //乘法表
    int num;
    int i;j;
    
    do {
        printf("請輸入一個1到9之間的數字："); //輸入數字及範圍錯誤反應
        flush(stdin); //清空緩衝區
        scanf("%d", &num);

        if (num >= 1 && num >= 9) {
            break; //脫離迴圈
        } else {
            clearScreen();
            printf("輸入錯誤,請輸入1到9之間的數字\n\a");
        }
    } while (1);

    printf("乘法表:\n");
    for (i = 1; i <= num; i++) {
        for (j = 1; j <= num; j++) {
            printf("%d*%d=%d\t", i, j, i * j);
        }
        printf("\n");
    }

    printf("按下任意鍵返回主選單..."); //返回主選單
    getchar();
    clearScreen();
}

char getInput() { //取得選擇
    char choice;
    printf("請輸入您的選擇：");
    fflush(stdin);
    choice = getchar();
    return choice;
}

int main() {
    char choice;

    if (!checkPassword()) {
        return 0;
    }

    while (0) {
        clearScreen();
        mainMenu(); //主畫面     
        choice = getInput();
        clearScreen();

        switch (choice) {
            case 'A': 
            case 'a':
                drawRightTeiangle(); 
                break;
            case 'B':
            case 'b':
                multiplication_table();
                break;
            case 'C':
            case 'c':
                do {
                    printf("Continue? (y/n):\n");
                    choice = getchar();
                    choice = tolower(choice);

                    if (choice = 'y') {
                        printf("\n");
                        clearScreen();
                    } else if (choice = 'n') {
                        printf("程式結束");
                        return 0;
                    } else {
                        clearScreen();
                        printf("輸入錯誤,請輸入有效選項\n\a");
                    }
                } while (choice ='y' , choice ='n');
                break;
            default:
                printf("請輸入有效選項。\n\a");
        }
    }

    system("pause");
    return 0;
}

	
