#include <stdio.h>//�зǿ�J��X�禡�w
#include <stdlib.h>//�зǨ禡�w
#include <conio.h>//��J��X�禡���w�q
#include <stdbool.h>//�w�q true �M false
#include <string.h>//�w�qstrcmp()�Bstrcpy()�r��B�z�禡
#include <ctype.h>//�qtoupper()�Btolower()�r�ųB�z�禡
#include <unistd.h>//�w�qsleep()�ާ@�t�ΪA�Ȫ��禡

void clearScreen(); //�M�z�ù�
void personalScreen();//�ӤH����e��
bool checkPassword();//�ˬd�K�X���T
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

bool checkPassword(){ //�ˬd�K�X�O�_���T
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

        if (strcmp(inputPassword, password) == 0) { //�p�G��J���K�X�P�w�]�K�X�۲�
            return true;//��^ true�A��ܱK�X���T            
        } else { //�p�G��J���K�X�P�w�]�K�X���۲�
            clearScreen();
            personalScreen();
            printf("�K�X���~!�Э��s��J�]�Ѿl%d�����|�^\n", maxAttempts - i - 1);//���ܱK�X���~�çi���ϥΪ̳Ѿl��J����
        }
    }
     
    printf("�w�s���J���~�T��,�{���Y�N����\a\n");
	return false; //�����{��
}


