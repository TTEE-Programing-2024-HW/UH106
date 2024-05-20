#include <stdio.h>// �зǿ�J��X�w
#include <stdlib.h>// �зǮw�A�]�A���s���t�B�L�{���
#include <conio.h>// ����x��J��X
#include <stdbool.h>// �]�t����������������Y���A����true�Mfalse�`�q�H��bool����
#include <string.h>// �r�Ŧ�ާ@���
#include <ctype.h>// �r���������
#include <unistd.h>// Unix�зǨ�ơ]�psleep���^
#include <time.h>// �ɶ��������

#define ROWS 9// �w�q�y��Ϫ����
#define COLS 9// �w�q�y��Ϫ��C��
#define BOOKED_SEATS 10// �w�q�y�쪺�ƶq

void clear_screen();// �M�̨�ƪ��n��
void personalScreen();// ��ܭӤH�H���̹�������n��
void resetSeatChart();// ���m�y��Ϫ�����n��
void randomBook();// �H���w�q�y�쪺����n��
void mainMenu();// �D����ƪ��n��
void displaySeatChart();// ��ܮy��Ϫ�����n��
bool autoBook();// �۰ʹw�q�y���ƪ��n��
bool manualBook();// ��ʹw�q�y���ƪ��n��
bool checkPassword();// �ˬd�K�X��ƪ��n��
char getInput(); // �����J��ƪ��n��

char seatChart[ROWS][COLS];// �y��Ϫ��G���r�Ű}�C(ROWS��MCOLS�C)
char choice;// �x�s�Τ�b�D��椤��ܪ��ﶵ('a','b','c','d')
char input[20]; // �x�s�Τ��J���r�Ŧ�(���׬�20)
int row, col;// ��M�C���ܶq
int numSeat; // �w�q�y��ƪ��ܶq
int mode, min = 1, max = 2;// �Ҧ���ܩM�H���ƽd���ܶq('min'�M'max'�w�q�F�H���ƥͦ����d��A�w�]��1�M2)
int row1, row2, col1, col2, col3, col4;// �x�s�h�Ӧ�M�C������
char *token;// �r�Ŧ���ΥΪ����w
char satisfaction; // �Τạ�N�ת��r���ܶq


void clear_screen() {
    system("cls"); // �ϥΨt�ΩR�O�M���̹�
}

void personalScreen() {
    printf("****************************************************************************\n");
    printf("*                                                                          *\n");
    printf("*                                                                          *\n");
    printf("*                     Created by H1.06�L�L��                               *\n");
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
// ���m�y��Ϫ����
void resetSeatChart() {
    for (int i = 0; i < ROWS; i++) { // �~�h�j��A�ΨӹM���@�椤���Ҧ�����
    for (int j = 0; j < COLS; j++) { // ���h�j��A�ΨӹM���C�@�椤���Ҧ��C
            seatChart[i][j] ='-';  // �N�C�Ӯy��]�m��'-'��ܥ��w�q
        }
    }
}
// �H���w�q�y�쪺���
void randomBook() { 
    srand(time(NULL)); // �η�e�ɶ��]�m�H���ƺؤl 
    for (int i = 0; i < BOOKED_SEATS; i++) { // �M���ݭn�w�q���y���
        row = rand() % ROWS; // �ͦ��@���H��������ޡA�d��b0��ROWS-1���� 
/*�o��N�X���ت��O�b0�MROWS-1�����ͦ��@���H���ơA�o�Ӽƭȷ|�Ψӧ@���y��Ϥ��������(�Ҧp�A�p�GROWS�O9�A����rand() % ROWS�����G�N�|�O0��8�������H����)*/
        col = rand() % COLS;// �ͦ��@���H�����C���ޡA�d��b0��COLS-1����
/*�o��N�X���ت��O�b0�MCOLS-1�����ͦ��@���H���ơA�o�Ӽƭȷ|�Ψӧ@���y��Ϥ����C����(�Ҧp�A�p�GCOLS�O9�A����rand() % COLS�����G�N�|�O0��8�������H����)*/
        seatChart[row][col] = '*'; // �N�H����w���y��аO��'*'��ܤw�w�q
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
    printf("���U���N���^�D���...");
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

