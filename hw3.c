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
    printf("| a. Available seats 		   |\n"); // �ﶵ�G��ܥi�ήy��
    printf("| b. Arrange for you	       	   |\n"); // �ﶵ�G�t�Φ۰ʬ��z�w�Ʈy��
    printf("| c. Choose by yourself 	   |\n"); // �ﶵ�G�ۤv��ܮy��
    printf("| d. Exit 			   |\n");
    printf("------------------------------------\n");
}

void displaySeatChart() {
    printf("\n  1 2 3 4 5 6 7 8 9\n"); // ���L�y��Ϫ��C��(1-9�C)
    for (int i = ROWS - 1; i >= 0; i--) { //�q�L�@�� for �`���q�����]�� ROWS ��^�쳻���]�� 1 ��^�M���y��Ϫ��C�@��A�渹�q ROWS �}�l����A�C������ 1 
        printf("%d", i + 1);//�b�C�檺�}�l���L�渹�A�渹�q 1 �� ROWS
        for (int j = 0; j < COLS; j++) { //�q 0 �}�l�A���� j ���� COLS�]�C�ơ^����C�b�o�Ӵ`�����A�C�����N���|�W�[ j ����
            printf(" %c", seatChart[i][j]); //���L��e��]�ѥ~�h�`�����ܶq i ��ܡ^�M��e�C�]�Ѥ��h�`�����ܶq j ��ܡ^��m���y�쪬�A
        }
        printf("\n");// �b�C�浲���ɴ���
    }
    printf("���U���N���^�D���...");// ���ܥΤ�����N���^�D���
    getch();// ���ݥΤ��J
    clear_screen();// �M��
}

bool autoBook() {
    srand(time(NULL));// �η�e�ɶ��@���H���ƥͦ������ؤl
    do {
        printf("how many seats do you need?\n");// ���ܥΤ��J�ݭn���y���
        fflush(stdout);// ��s��X�w�İ�
        if (scanf("%d", &numSeat)!= 1) { // Ū���y��ƨ��ˬd��J�O�_����
            clear_screen();// �p�G��J�L�ġA�M��
            printf("invalid input please try again\n");// �q���Τ��J�L��

            while (getchar() != '\n');// �M����J�w�İ�
            continue;// ���s�}�l�`��
        }

        if (numSeat < 1 || numSeat > 4) { // �p�G�W�X�d��(�p��1�H�U �Τj��4�H�W) 
            clear_screen();// �M��
            printf("invalid input please try again\n");// �q���Τ��J�L��
        }
    } while (numSeat < 1 || numSeat > 4);// ���ƪ����J���Įy���

    do {
        bool found = false;// �лx�O�_��즳�Ī��y��w��
        if (numSeat < 4) { // �p�p�G�ݭn���y��Ƥp��4�A�i�J�o�q�{���X
            if (numSeat == 1) { // �p�G�u�ݭn�@�Ӯy��
                do {
                    row1 = rand() % ROWS; //�ϥ��H���ƥͦ����H����ܤ@��
                    col1 = rand() % (COLS - numSeat + 1);// �H���ͦ��C
                } while (seatChart[row1][col1] == '*');// �p�G�y��w�Q�w�q�A���Ʀ��L�{
                seatChart[row1][col1] = '@';// �ȮɼаO�Ӯy��w�w�q
                found = true;// �аO��즳�Ī��y��w��
            } else if (numSeat == 2) { // �p�G�ݭn��Ӯy��
                do {
                    row1 = rand() % ROWS;//�ϥ��H���ƥͦ����H����ܤ@��
                    col1 = rand() % (COLS - numSeat + 1);// �H���ͦ��C���A�T�O���������s��y��
                    col2 = (col1 + 1) % COLS;// �p��ĤG�Ӯy�쪺�C���A�T�O���O�s��
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*');// �p�G����@�Ӯy��w�Q�w�q�A���Ʀ��L�{
                seatChart[row1][col1] = '@';// �ȮɼаO�Ĥ@�Ӯy��w�w�q
                seatChart[row1][col2] = '@'; // �ȮɼаO�ĤG�Ӯy��w�w�q
                found = true;// �аO��즳�Ī��y��w��
            } else if (numSeat == 3) {// �p�G�ݭn�T�Ӯy��
                do {
                    row1 = rand() % ROWS;// �H���ͦ��渹
                    col1 = rand() % (COLS - numSeat + 1);// �H���ͦ��C���A�T�O���������s��y��
                    col2 = (col1 + 1) % COLS;// �p��ĤG�Ӯy�쪺�C���A�T�O���O�s�� 
                    col3 = (col2 + 1) % COLS;// �p��ĤT�Ӯy�쪺�C���A�T�O���O�s��
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row1][col3] == '*');// �p�G����@�Ӯy��w�Q�w�q�A���Ʀ��L�{
                seatChart[row1][col1] = '@';// �ȮɼаO�Ĥ@�Ӯy��w�w�q
                seatChart[row1][col2] = '@';// �ȮɼаO�ĤG�Ӯy��w�w�q
                seatChart[row1][col3] = '@';// �ȮɼаO�ĤT�Ӯy��w�w�q
                found = true;// �аO��즳�Ī��y��w��
            }
        } else {// �_�h�A�p�G�ݭn���y��Ƭ��|��
            mode = rand() % (max - min + 1) + 1;//�ͦ��@�Ӥ��� min �M max �������H�����
            mode = mode % 2;//�N���e�ͦ����H���ƨ��l�ư��H 2�A�H��o�@�ӽd��b 0 �� 1 �������H����
            if (mode == 0) { // �p�G�Ҧ���0�A��ܿ�ܳs��|�Ӯy��
                do {
                    row1 = rand() % ROWS;// �H���ͦ���
                    col1 = rand() % (COLS - numSeat + 1);// �H���ͦ��C���A�T�O���������s��y��
                    col2 = (col1 + 1) % COLS;// �p��ĤG�Ӯy�쪺�C���A�T�O���O�s��
                    col3 = (col2 + 1) % COLS;// �p��ĤT�Ӯy�쪺�C���A�T�O���O�s��
                    col4 = (col3 + 1) % COLS;// �p��ĥ|�Ӯy�쪺�C���A�T�O���O�s��
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row1][col3] == '*' || seatChart[row1][col4] == '*');// �p�G����@�Ӯy��w�Q�w�q�A���Ʀ��L�{
                seatChart[row1][col1] = '@';// �аO�Ĥ@�Ӯy��w�w�q
                seatChart[row1][col2] = '@';// �аO�ĤG�Ӯy��w�w�q
                seatChart[row1][col3] = '@';// �аO�ĤT�Ӯy��w�w�q
                seatChart[row1][col4] = '@';// �аO�ĥ|�Ӯy��w�w�q
                found = true;// �аO��즳�Ī��y��w��
            } else { // �_�h�A���2+2 �y��Ҧ�
                do {
                    row1 = rand() % (ROWS - 1);// �H���ͦ��Ĥ@��
                    row2 = (row1 + 1) % ROWS;// �p��ĤG�渹�A�T�O���O�s��
                    col1 = rand() % (COLS - numSeat + 1);// �H���ͦ��C���A�T�O���������s��y��
                    col2 = (col1 + 1) % COLS;// �p��ĤG�Ӯy�쪺�C���A�T�O���O�s��
                } while (seatChart[row1][col1] == '*' || seatChart[row1][col2] == '*' || seatChart[row2][col1] == '*' || seatChart[row2][col2] == '*');// �p�G����@�Ӯy��w�Q�w�q�A���Ʀ��L�{
                seatChart[row1][col1] = '@';// �аO�Ĥ@�Ӯy��w�w�q
                seatChart[row1][col2] = '@';// �аO�ĤG�Ӯy��w�w�q
                seatChart[row2][col1] = '@';// �аO�ĤT�Ӯy��w�w�q
                seatChart[row2][col2] = '@';// �аO�ĥ|�Ӯy��w�w�q
                found = true;// �аO��즳�Ī��y��w��
            }
        }
        
        printf("\n  1 2 3 4 5 6 7 8 9\n");// ���L�C��(1-9)
        for (int i = ROWS - 1; i >= 0; i--) {//�Ӱj��q�y��Ϫ��̫�@��}�l�V�W�M���C ROWS - 1 ��ܱq�y��Ϫ��̫�@��}�l
            printf("%d", i + 1);// ���L�渹
                for (int j = 0; j < COLS; j++) {//�q�Ӧ檺�Ĥ@�Ӯy��}�l�A��p�ƾ� j �p��C�ƮɡA�j���~�����
                    printf(" %c", seatChart[i][j]);//��ܮy��Ϥ��� i ��B�� j �C���y�쪬�A
            }
        printf("\n");// �b�C�浲���ɴ���
        }

        printf("are you satisfaction with the suggested seats? (Y/N)\n");// ��ܮy���ĳ�O�_���N
        fflush(stdout);// ��s��X�w�İ�
        satisfaction = getch();// ����Τạ�N��
        satisfaction = tolower(satisfaction);// �N��J�ഫ���p�g
        if (satisfaction != 'y') { // �p�G�����N
            clear_screen();// �M�ſù�
            for (int i = 0; i < ROWS; i++) {// �M���C�@��
                for (int j = 0; j < COLS; j++) {// �M���C�@�C
                    if (seatChart[i][j] == '@') {// �p�G�y��w�w�q
                        seatChart[i][j] = '-';// �N�y�쪬�A�]�m���Ŷ�
                    }
                }
            }
        } else {// �p�G���N
            for (int i = 0; i < ROWS; i++) { // �M���C�@��
                for (int j = 0; j < COLS; j++) { // �M���C�@�C
                    if (seatChart[i][j] == '@') {// �p�G�y��w�w�q
                     seatChart[i][j] = '*';// �N�y�쪬�A�]�m���w�w�q
					}
                }
            }
            printf("press enter to continue...\n");// ���ܥΤ�� Enter ���~��
            getch();// ���ݥΤ����
            clear_screen();// �M�ſù�
            break;// ���X�j��
        }
    } while (true); // �L���j�骽��Τạ�N

    clear_screen();// �M�ſù�
    return 0;// ��^��ƭ�
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

