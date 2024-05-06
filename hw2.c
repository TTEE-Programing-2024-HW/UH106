#include <stdio.h>//�зǿ�J��X�禡�w
#include <stdlib.h>//�зǨ禡�w
#include <conio.h>//��J��X�禡���w�q
#include <stdbool.h>//�w�q true �M false
#include <string.h>//�w�qstrcmp()�Bstrcpy()�r��B�z�禡
#include <ctype.h>//�qtoupper()�Btolower()�r�ųB�z�禡
#include <unistd.h>//�w�qsleep()�ާ@�t�ΪA�Ȫ��禡

void cleanScreen(); //�M�z�ù�
void personalScreen();//�ӤH����e��
void boolean checkPassword();//�ˬd�K�X���T
void mainMenu();//�D�e��
void drawRightTeiangle(); //�e�����T����
void multiplication_table();//���k��
char getInput();//���o���

void clearScreen() //�M�z�ù�
{     
    system("cls");      
} 

void personalScreen() { 
	printf("****************************************************************************\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
    printf("*                          Created by H1.06�L�L��                          *\n");
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

void boolean checkPassword(){ //�ˬd�K�X�O�_���T
     char password[] = "2024"; //�]�w�w�]�K�X
     char inputPassword[5]; //�]�w��J�K�X
     int passwordAttempts=3; //�]�w���զ���
     int maxAttempts = 3; //�]�w�̤j���զ���
     for (int i = 0; i < maxAttempts; i++)//���ұK�X
	 { 
        clearScreen();//�M�z�ù�
        personalScreen(); //��ܭӤH����e��
        printf("�п�J�|��Ʀr�K�X�]2024�^:");
        fgets(inputPassword, sizeof(inputPassword), stdin);//�ϥ� fgets �q�зǿ�J(stdin)Ū���ϥΪ̿�J���K�X�A�æs�x�b inputPassword ��

        if (strcmp(inputPassword, password) == 0) {
            return true;            
        } else {
            clearScreen();
            personalScreen();
            printf("�K�X���~!�Э��s��J\n");
        }
    }
    printf("�w�s���J���~�T��,�{���Y�N����\a\n");
	return false; 
}

void mainMenu() { // �D�e��
    printf("--------------------------\n");
    printf("|  a. �e�X�����T����    |\n");
    printf("|  b. ��ܭ��k��        |\n");
    printf("|  c. ����                |\n");
    printf("--------------------------\n");
}
void drawRightTeiangle() { //�e�����T����
    char ch;
    int i;j;
    int n;

    do {
        printf("�п�J�@�Ӧr��]a��n�����^�G"); //��J�r��νd����~����
        flush(stdin); //�M�Žw�İ�
        scanf("%s", &ch);

        if ((ch >= 'a' && ch <= 'n')(ch >='A' && ch <= 'N')) {
            break; //�����j��
        } else {
            clearScreen();
            printf("��J���~,�п�Ja��n�������r��\n\a");
        }
    } while (1);

    printf("�T����:\n");
    if (islower(ch))
	 {
        n = ch - 'a' + 1;
    } 
	else if (isupper(ch)) 
	{
        n = ch - 'A' + 1;
    }

    for (i = 1; i <= n; i++) { // ���L�Ů�  
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (j = 1; j <= i; j++) { // ���L�r��
            if (islower(ch))
                printf("%s", ch - (i - j));
            else if (isupper(ch))
                printf("%s", toupper(ch) - (i - j));
        }

        printf("\n");
    }

    printf("���U���N���^�D���..."); //��^�D���
    getchar();
    clearScreen();
}

void multiplication_table() { //���k��
    int num;
    int i;j;
    
    do {
        printf("�п�J�@��1��9�������Ʀr�G"); //��J�Ʀr�νd����~����
        flush(stdin); //�M�Žw�İ�
        scanf("%d", &num);

        if (num >= 1 && num >= 9) {
            break; //�����j��
        } else {
            clearScreen();
            printf("��J���~,�п�J1��9�������Ʀr\n\a");
        }
    } while (1);

    printf("���k��:\n");
    for (i = 1; i <= num; i++) {
        for (j = 1; j <= num; j++) {
            printf("%d*%d=%d\t", i, j, i * j);
        }
        printf("\n");
    }

    printf("���U���N���^�D���..."); //��^�D���
    getchar();
    clearScreen();
}

char getInput() { //���o���
    char choice;
    printf("�п�J�z����ܡG");
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
        mainMenu(); //�D�e��     
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
                        printf("�{������");
                        return 0;
                    } else {
                        clearScreen();
                        printf("��J���~,�п�J���Ŀﶵ\n\a");
                    }
                } while (choice ='y' , choice ='n');
                break;
            default:
                printf("�п�J���Ŀﶵ�C\n\a");
        }
    }

    system("pause");
    return 0;
}

	
