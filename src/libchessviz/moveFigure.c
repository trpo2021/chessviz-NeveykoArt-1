#include "chess.h"

static enum BlackWhite getColor(char figure)
{
    if (islower(figure)) {
        return Black;
    } else {
        return White;
    }
}

static bool checkAbilityP(motion the_motion, char chess[8][8])
{
    int start_y = the_motion.start_position_y;
    int start_x = the_motion.start_position_x;
    int end_y = the_motion.end_position_y;
    int end_x = the_motion.end_position_x;

    int direction, start_horizont;
    char figure;
    if (getColor(chess[start_y][start_x]) == White) {
        direction = 1;
        start_horizont = 6; 
        figure = 'p';
    } else {
        direction = -1;
        start_horizont = 1;
        figure = 'P';
    }

    int delta_y = direction * (start_y - end_y);
    int delta_x = direction * (start_x - end_x);

    if ((delta_y == 1) && (start_x == end_x)) {
        return true;
    } else if (
            (delta_y == 2) && (start_x == end_x)
            && (chess[end_y + direction][start_x] == ' ')
            && (start_y == start_horizont)) {
        return true;
    } else if (
            (the_motion.flag_ep == 1) && (delta_y == 1) && (abs(delta_x) == 1)
            && (chess[start_y][end_x] == figure)) {
        return true;
    } else if (
            (the_motion.type_motion == 1) && (delta_y == 1)
            && (abs(delta_x) == 1)) {
        return true;
    }
    return false;
}

static bool checkAbilityEP(motion the_motion, char chess[8][8])
{
    int end_y = the_motion.end_position_y;
    int end_x = the_motion.end_position_x;

    if (chess[end_y][end_x] != 'K' && chess[end_y][end_x] != 'k'
        && the_motion.flag_ep == 1 && (chess[end_y][end_x] == ' ')) {
        return true;
    }
    return false;
}

static bool checkAbilityB(motion the_motion, char chess[8][8])
{
    int start_y = the_motion.start_position_y;
    int start_x = the_motion.start_position_x;
    int end_y = the_motion.end_position_y;
    int end_x = the_motion.end_position_x;
    int delta_x = abs(end_x - start_x);
    int delta_y = abs(end_y - start_y);

    if (delta_x != delta_y) {
        return false;
    }

    int direction_x;
    int direction_y;

    if (start_y > end_y) {
        direction_y = -1;
    } else {
        direction_y = 1;
    }

    if (start_x > end_x) {
        direction_x = -1;
    } else {
        direction_x = 1;
    }

    for (int i = 1; i < delta_x - 1; ++i)
        if (chess[start_y + i * direction_y][start_x + i * direction_x]
            != ' ') {
            return false;
        }

    return true;
}

static bool checkAbilityN(motion the_motion)
{
    int start_y = the_motion.start_position_y;
    int start_x = the_motion.start_position_x;
    int end_y = the_motion.end_position_y;
    int end_x = the_motion.end_position_x;

    if ((abs(start_y - end_y) == 1 && abs(start_x - end_x) == 2)
        || (abs(start_y - end_y) == 2 && abs(start_x - end_x) == 1)) {
        return true;
    }

    return false;
}

static bool checkAbilityR(motion the_motion, char chess[8][8])
{
    int start_y = the_motion.start_position_y;
    int start_x = the_motion.start_position_x;
    int end_y = the_motion.end_position_y;
    int end_x = the_motion.end_position_x;

    if (start_y < end_y) {
        for (int i = (start_y + 1); i < end_y; ++i) {
            if (chess[i][start_x] != ' ')
                return false;
        }

    } else if (start_y > end_y) {
        for (int i = (start_y - 1); i > end_y; --i) {
            if (chess[i][start_x] != ' ')
                return false;
        }

    } else {
        if (start_x < end_x) {
            for (int i = (start_x + 1); i < end_x; ++i) {
                if (chess[start_y][i] != ' ')
                    return false;
            }
        } else if (start_x > end_x) {
            for (int i = (start_x - 1); i > end_x; --i) {
                if (chess[start_y][i] != ' ')
                    return false;
            }
        }
    }

    return true;
}

static bool checkAbilityK(motion the_motion)
{
    int start_y = the_motion.start_position_y;
    int start_x = the_motion.start_position_x;
    int end_y = the_motion.end_position_y;
    int end_x = the_motion.end_position_x;

    if ((abs(start_y - end_y) == 1 && abs(start_x - end_x) == 1)
        || (abs(start_y - end_y) == 1 && start_x == end_x)
        || (abs(start_x - end_x) == 1 && start_y == end_y)) {
        return true;
    }

    return false;
}

static bool checkAbilityCastling(motion the_motion, char chess[8][8])
{
    int line;
    if (the_motion.color == White) {
        line = 7;
    } else {
        line = 0;
    }

    if (the_motion.castling == Short) {
      if (((chess[line][4] == 'K' && chess[line][7] == 'R')
           || (chess[line][4] == 'k' && chess[line][7] == 'r'))
          && chess[line][5] == ' ' && chess[line][6] == ' ')
          return true;
    } else if (the_motion.castling == Long) {
        if (((chess[line][4] == 'K' && chess[line][0] == 'R')
             || (chess[line][4] == 'k' && chess[line][0] == 'r'))
            && chess[line][3] == ' ' && chess[line][2] == ' '
            && chess[line][1] == ' ')
            return true;
    }

    return false;
}

static bool checkStartPosition(motion the_motion, char chess[8][8])
{
    int start_y = the_motion.start_position_y;
    int start_x = the_motion.start_position_x;

    char figure;
    if (the_motion.color == Black) {
        figure = tolower(the_motion.figure);
    } else {
        figure = the_motion.figure;
    }

    if (chess[start_y][start_x] == figure) {
        return true;
    }

    return false;
}

static bool checkEndPosition(motion the_motion, char chess[8][8])
{
    int end_y = the_motion.end_position_y;
    int end_x = the_motion.end_position_x;

    if (the_motion.type_motion == 0 && chess[end_y][end_x] == ' ') {
        return true;
    } else if (chess[end_y][end_x] != 'K' && chess[end_y][end_x] != 'k')
        if (the_motion.color != getColor(chess[end_y][end_x])) {
            return true;
        }

    return false;
}

static void makeMove(motion the_motion, char chess[8][8])
{
    int start_y = the_motion.start_position_y;
    int start_x = the_motion.start_position_x;
    int end_y = the_motion.end_position_y;
    int end_x = the_motion.end_position_x;

    if (the_motion.figure == 'P' && the_motion.flag_ep == 1) {
        chess[start_y][end_x] = ' ';
    }

    chess[end_y][end_x] = chess[start_y][start_x];
    chess[start_y][start_x] = ' ';
}

static void makeTransformation(motion the_motion, char chess[8][8])
{
    int start_y = the_motion.start_position_y;
    int start_x = the_motion.start_position_x;
    int end_y = the_motion.end_position_y;
    int end_x = the_motion.end_position_x;

    if (getColor(chess[start_y][start_x]) == White)
        chess[end_y][end_x] = the_motion.transformation_figure;
    else
        chess[end_y][end_x] = tolower(the_motion.transformation_figure);

    chess[start_y][start_x] = ' ';
}

static void makeCastling(motion the_motion, char chess[8][8])
{
    int line;
    if (the_motion.color == White) {
        line = 7;
    } else {
        line = 0;
    }

    if (the_motion.castling == Short) {
        chess[line][6] = chess[line][4];
        chess[line][4] = ' ';
        chess[line][5] = chess[line][7];
        chess[line][7] = ' ';
    } else if (the_motion.castling == Long) {
        chess[line][2] = chess[line][4];
        chess[line][4] = ' ';
        chess[line][3] = chess[line][0];
        chess[line][0] = ' ';
    }
}

bool moveP(motion the_motion, char chess[8][8])
{
    if (!checkAbilityP(the_motion, chess)
        || !checkStartPosition(the_motion, chess)
        || !(checkEndPosition(the_motion, chess)
             || checkAbilityEP(the_motion, chess))) {
        return false;
    }

    if (the_motion.flag_transformation == 1) {
        makeTransformation(the_motion, chess);
    } else
        makeMove(the_motion, chess);

    return true;
}

bool moveB(motion the_motion, char chess[8][8])
{
    if (!checkAbilityB(the_motion, chess)
        || !checkStartPosition(the_motion, chess)
        || !checkEndPosition(the_motion, chess)) {
        return false;
    }

    makeMove(the_motion, chess);
    return true;
}

bool moveN(motion the_motion, char chess[8][8])
{
    if (!checkAbilityN(the_motion) || !checkStartPosition(the_motion, chess)
        || !checkEndPosition(the_motion, chess)) {
        return false;
    }

    makeMove(the_motion, chess);
    return true;
}

bool moveR(motion the_motion, char chess[8][8])
{
    if (!checkAbilityR(the_motion, chess)
        || !checkStartPosition(the_motion, chess)
        || !checkEndPosition(the_motion, chess)) {
        return false;
    }

    makeMove(the_motion, chess);
    return true;
}

bool moveQ(motion the_motion, char chess[8][8])
{
    if (!(checkAbilityR(the_motion, chess) || checkAbilityB(the_motion, chess))
        || !checkStartPosition(the_motion, chess)
        || !checkEndPosition(the_motion, chess)) {
        return false;
    }

    makeMove(the_motion, chess);
    return true;
}

bool moveK(motion the_motion, char chess[8][8])
{
    if (!checkAbilityK(the_motion) || !checkStartPosition(the_motion, chess)
        || !checkEndPosition(the_motion, chess)) {
        return false;
    }

    makeMove(the_motion, chess);
    return true;
}

bool moveCastling(motion the_motion, char chess[8][8])
{
    if (!checkAbilityCastling(the_motion, chess)) {
        return false;
    }

    makeCastling(the_motion, chess);
    return true;
}
