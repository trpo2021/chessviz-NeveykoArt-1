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
        start_horizont = 6; //?
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
    return false;
}

bool moveN(motion the_motion, char chess[8][8])
{
    return false;
}

bool moveK(motion the_motion, char chess[8][8])
{
    return false;
}

bool moveQ(motion the_motion, char chess[8][8])
{
    return false;
}

bool moveR(motion the_motion, char chess[8][8])
{
    return false;
}
