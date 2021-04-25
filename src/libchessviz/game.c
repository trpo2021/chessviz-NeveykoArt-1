#include "chess.h"

void createChess(char chess[8][8])
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            chess[i][j] = ' ';

    //пешки белого
    for (int i = 0; i < 8; ++i)
        chess[6][i] = 'P';

    //пешки черного
    for (int i = 0; i < 8; ++i)
        chess[1][i] = 'p';

    //белые фигуры
    char white[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for (int i = 0; i < 8; ++i) {
        chess[7][i] = white[i];
    }

    //черные фигуры
    char black[8] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    for (int i = 0; i < 8; ++i) {
        chess[0][i] = black[i];
    }
}

void printChess(char chess[8][8])
{
    char numbers[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    char letter[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    for (int i = 0; i < 8; ++i) {
        printf("\t");
        for (int j = 0; j < 8; ++j) {
            printf(" %c ", chess[i][j]);
        }
        printf(" %c\n", numbers[7 - i]);
    }
    printf("\t");
    for (int i = 0; i < 8; ++i)
        printf(" %c ", letter[i]);
    printf("\n");
}

void print_the_motion(motion the_motion)
{
    printf("Color = %d\n", the_motion.color);
    printf("Figure = %c\n", the_motion.figure);
    printf("Start_position_x = %d \n", the_motion.start_position_x);
    printf("Start_position_y = %d\n", the_motion.start_position_y);
    printf("Type = %d\n", the_motion.type_motion);
    printf("End_position_x = %d\n", the_motion.end_position_x);
    printf("End_position_y = %d\n", the_motion.end_position_y);
    printf("Castling = %d\n", the_motion.castling);
}

bool _move(motion the_motion, char chess[8][8])
{
    bool result = false;

    switch (the_motion.figure) {
    case 'P':
        result = moveP(the_motion, chess);
        break;
    case 'B':
        result = moveB(the_motion, chess);
        break;
    case 'N':
        result = moveN(the_motion, chess);
        break;
    case 'Q':
        result = moveQ(the_motion, chess);
        break;
    case 'K':
        //  result = moveK(the_motion, chess);
        break;
    case 'R':
        result = moveR(the_motion, chess);
        break;
    }
    return result;
}

motion initMotion()
{
    motion the_motion
            = {.type_motion = false,

               .flag_shah = false,
               .flag_cmate = false,
               .flag_ep = false,
               .flag_transformation = false,
               .transformation_figure = ' ',

               .castling = Without};

    return the_motion;
}
