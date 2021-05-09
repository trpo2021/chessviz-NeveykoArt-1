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

bool _move(motion the_motion, char chess[8][8])
{
    switch (the_motion.figure) {
    case 'P':
        return moveP(the_motion, chess);
    case 'B':
        return moveB(the_motion, chess);
    case 'N':
        return moveN(the_motion, chess);
    case 'Q':
        return moveQ(the_motion, chess);
    case 'K':
        return moveK(the_motion, chess);
    case 'R':
        return moveR(the_motion, chess);
    }

    if (the_motion.castling != Without) {
        return moveCastling(the_motion, chess);
    }

    return false;
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

match initMatch()
{
    match match_;
    match_.white_motion = initMotion();
    match_.black_motion = initMotion();

    match_.white_motion.color = White;
    match_.black_motion.color = Black;

    return match_;
}

void visualizationChess(char chess[8][8], match* match_, int count_moves)
{
    FILE* file_html = fopen("../bin/chess.html", "w+");
    addStartHTML(file_html);
    addChessHTML(file_html, chess, "");

    printf("Start chess table:\n");
    printChess(chess);
    for (int i = 0; i < count_moves; i++) {
        _move(match_[i].white_motion, chess);
        addChessHTML(file_html, chess, match_[i].id_move);
        printf("%d  White:\n", atoi_new(match_[i].id_move));
        printChess(chess);

        if (match_[i].white_motion.flag_cmate == true) {
            printf("\tWhite Wins\n!");
            break;
        }

        _move(match_[i].black_motion, chess);
        addChessHTML(file_html, chess, match_[i].id_move);
        printf("%d  Black:\n", atoi_new(match_[i].id_move));
        printChess(chess);

        if (match_[i].black_motion.flag_cmate == true) {
            printf("\t\tBlack Wins!\n");
            break;
        }
    }

    printf("\n\t\tThe end\n");

    addEndHTML(file_html);
    fclose(file_html);
}

void testPrint(char chess[8][8], match match_)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);
}
