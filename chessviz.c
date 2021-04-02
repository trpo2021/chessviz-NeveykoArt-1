#include <stdio.h>
#include <stdlib.h>

void createChess(char chess[9][9])
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            chess[i][j] = ' ';

    //нумерование клеток
    chess[0][8] = '1';
    chess[1][8] = '2';
    chess[2][8] = '3';
    chess[3][8] = '4';
    chess[4][8] = '5';
    chess[5][8] = '6';
    chess[6][8] = '7';
    chess[7][8] = '8';
    //нумерование клеток
    chess[8][0] = 'a';
    chess[8][1] = 'b';
    chess[8][2] = 'c';
    chess[8][3] = 'd';
    chess[8][4] = 'e';
    chess[8][5] = 'f';
    chess[8][6] = 'g';
    chess[8][7] = 'h';

    //белые пешки
    for (int i = 0; i < 8; ++i)
        chess[6][i] = 'P';

    //черные пешки
    for (int i = 0; i < 8; ++i)
        chess[1][i] = 'p';

    //белые фигуры
    chess[7][0] = 'R';
    chess[7][1] = 'N';
    chess[7][2] = 'B';
    chess[7][3] = 'Q';
    chess[7][4] = 'K';
    chess[7][5] = 'B';
    chess[7][6] = 'N';
    chess[7][7] = 'R';
    //черные фигуры
    chess[0][0] = 'r';
    chess[0][1] = 'n';
    chess[0][2] = 'b';
    chess[0][3] = 'q';
    chess[0][4] = 'k';
    chess[0][5] = 'b';
    chess[0][6] = 'n';
    chess[0][7] = 'r';
}

void printChess(char chess[9][9])
{
    for (int i = 0; i < 9; ++i) {
        printf("\t");
        for (int j = 0; j < 9; ++j) {
            printf(" %c ", chess[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    char chess[9][9];

    createChess(chess);

    printf("Start chess table:\n");
    printChess(chess);

    return 0;
}
