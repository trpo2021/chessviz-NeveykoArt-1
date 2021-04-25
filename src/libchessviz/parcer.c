#include "chess.h"

bool checkNumberMove(char* number_move)
{
    if (number_move == NULL) {
        return false;
    } else {
        int size = strlen(number_move);
        if (size == 1)
            return false;

        if (number_move[size - 1] != '.')
            return false;

        if (number_move[0] == '0')
            return false;

        for (int i = 0; i < size - 1; i++)
            if (number_move[i] < '0' || number_move[i] > '9')
                return false;
    }

    return true;
}

bool checkMove(char* move, motion* the_motion, enum BlackWhite color)
{
    if (move == NULL)
        return false;

    the_motion->color = color;

    if (strcmp(move, "0-0") == 0) {
        the_motion->castling = Short;
        return true;
    }

    if (strcmp(move, "0-0-0") == 0) {
        the_motion->castling = Long;
        return true;
    }

    the_motion->castling = Without;

    int position = 0;
    int size = strlen(move);

    if (size < 5)
        return false;

    //какой фигурой будет ход
    if (strchr("NBKQR", move[position]) != NULL) {
        the_motion->figure = move[position];
        position++;
    } else {
        the_motion->figure = 'P';
    }

    if (checkPositionMove(move[position], move[position + 1])) {
        if (checkPositionMove(move[position + 3], move[position + 4])) {
            the_motion->start_position_x = move[position] - 'a';
            the_motion->start_position_y = 7 - (move[position + 1] - '1');

            the_motion->end_position_x = move[position + 3] - 'a';
            the_motion->end_position_y = 7 - (move[position + 4] - '1');
        } else {
            return false;
        }
    } else {
        return false;
    }

    if (move[position + 2] == '-') {
        the_motion->type_motion = false;
    } else if (move[position + 2] == 'x') {
        the_motion->type_motion = true;
    } else {
        return false;
    }

    position += 5;
    if (position == size || (position + 1 == size && move[position] == '\n'))
        return true;

    if (strchr("NBRQ", move[position]) != NULL && the_motion->figure == 'P') {
        the_motion->transformation_figure = move[position];
        the_motion->flag_transformation = true;
        position++;
    } else if (size >= position + 4) //может присутствовать e.p.
    {
        if (move[position] == 'e' && move[position + 1] == '.'
            && move[position + 2] == 'p' && move[position + 3] == '.'
            && the_motion->figure == 'P') {
            the_motion->flag_ep = true;
            position += 4;
        } else {
            return false;
        }
    }

    if (position == size || (position + 1 == size && move[position] == '\n'))
        return true;

    if (size == position + 1) {
        if (move[position] == '+') {
            the_motion->flag_shah = true;
            return true;
        }

        if (move[position] == '#') {
            the_motion->flag_cmate = true;
            return true;
        }

        return false;
    }

    return false;
}

bool checkPositionMove(char symbol, char number)
{
    if (symbol >= 'a' && symbol <= 'h')
        if (number >= '1' && number <= '8')
            return true;
    return false;
}
