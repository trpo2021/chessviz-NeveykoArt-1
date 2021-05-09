#include "chess.h"

int atoi_new(char* id_move)
{
    char buf[4];

    strncpy(buf, id_move, strlen(id_move) - 1);

    return atoi(buf);
}

static bool checkNumberMove(char* number_move)
{
    if (number_move == NULL) {
        return false;
    }

    int size = strlen(number_move);

    if (size == 1 || size > 5)
        return false;

    if (number_move[size - 1] != '.')
        return false;

    if (number_move[0] == '0')
        return false;

    for (int i = 0; i < size - 1; i++)
        if (number_move[i] < '0' || number_move[i] > '9')
            return false;

    return true;
}

static bool checkCastling(char* move, motion* the_motion)
{
    if (strncmp(move, " 0-0-0 ", 7) == 0) {
        the_motion->castling = Long;
        return true;
    }
    if (strncmp(move, " 0-0 ", 5) == 0) {
        the_motion->castling = Short;
        return true;
    }
    the_motion->castling = Without;
    return false;
}

static bool checkFigure(char* move, motion* the_motion, size_t* position)
{
    if (strchr("KQRBN", move[*position]) != NULL) {
        the_motion->figure = move[*position];
        ++(*position);
    } else {
        the_motion->figure = 'P';
    }
    return true;
}

static bool checkPosition(char symbol, char number)
{
    if (symbol >= 'a' && symbol <= 'h')
        if (number >= '1' && number <= '8')
            return true;
    return false;
}

static bool checkStartPosition(char* move, motion* the_motion, size_t* position)
{
    if (checkPosition(move[*position], move[*position + 1])) {
        the_motion->start_position_x = move[*position] - 'a';
        the_motion->start_position_y = 7 - (move[*position + 1] - '1');
        *position += 2;
        return true;
    }
    return false;
}

static bool checkTypeMotion(char* move, motion* the_motion, size_t* position)
{
    if (move[*position] == '-') {
        the_motion->type_motion = false;
        ++(*position);
    } else if (move[*position] == 'x') {
        the_motion->type_motion = true;
        ++(*position);
    } else {
        return false;
    }
    return true;
}

static bool checkEndPosition(char* move, motion* the_motion, size_t* position)
{
    if (checkPosition(move[*position], move[*position + 1])) {
        the_motion->end_position_x = move[*position] - 'a';
        the_motion->end_position_y = 7 - (move[*position + 1] - '1');
        *position += 2;
        return true;
    }
    return false;
}

static void
checkTransformation(char* move, motion* the_motion, size_t* position)
{
    if (((move[*position] == 'B') || (move[*position] == 'N')
         || (move[*position] == 'R') || (move[*position] == 'Q'))
        && the_motion->figure == 'P') {
        the_motion->transformation_figure = move[*position];
        the_motion->flag_transformation = true;
        ++(*position);
    }
}

static void checkEP(char* move, motion* the_motion, size_t* position)
{
    if (move[*position] == 'e' && move[*position + 1] == '.'
        && move[*position + 2] == 'p' && move[*position + 3] == '.'
        && the_motion->figure == 'P' && the_motion->type_motion == true) {
        the_motion->flag_ep = true;
        *position += 4;
    }
}

static void checkCMateShah(char* move, motion* the_motion, size_t* position)
{
    if (move[*position] == '#') {
        the_motion->flag_cmate = true;
        ++(*position);
    }

    if (move[*position] == '+') {
        the_motion->flag_shah = true;
        ++(*position);
    }
}

bool checkMove(char* move, motion* the_motion)
{
    size_t position = 0;

    if (checkCastling(move, the_motion)) {
        return true;
    }

    if (!(checkFigure(move, the_motion, &position)
          && checkStartPosition(move, the_motion, &position)
          && checkTypeMotion(move, the_motion, &position)
          && checkEndPosition(move, the_motion, &position))) {
        return false;
    }

    checkTransformation(move, the_motion, &position);
    checkEP(move, the_motion, &position);
    checkCMateShah(move, the_motion, &position);

    if (strlen(move) == position) {
        return true;
    }

    return false;
}

bool checkLine(char* line, match* match_)
{
    char* word_id = strtok(line, " ");

    if (!checkNumberMove(word_id)) {
        return false;
    }
    strcpy(match_->id_move, word_id);

    char* move_white = strtok(NULL, " \n");
    if (!checkMove(move_white, &match_->white_motion)) {
        return false;
    }
    match_->white_motion.color = White;

    if (!match_->white_motion.flag_cmate) {
        char* move_black = strtok(NULL, " \n");
        if (!checkMove(move_black, &match_->black_motion)) {
            return false;
        }
        match_->black_motion.color = Black;
    }

    return true;
}

match* Read_file(FILE* file, int* count_moves)
{
    const int MAX_COUNT_CHARS = 80;

    char* buf_line = malloc(MAX_COUNT_CHARS * sizeof(char));

    while (!feof(file)) {
        fgets(buf_line, MAX_COUNT_CHARS, file);
        ++(*count_moves);
    }

    --(*count_moves);

    match* match_ = malloc(*count_moves * sizeof(match));

    rewind(file);

    for (int i = 0; i < *count_moves; i++) {
        fgets(buf_line, MAX_COUNT_CHARS, file);
        if (!checkLine(buf_line, &(match_[i]))) {
            free(match_);
            return NULL;
        }
    }

    for (int i = 0; i < *count_moves; ++i) {
        if (!(atoi_new(match_[i].id_move) == (i + 1))) {
            free(match_);
            printf("Error: wrong sequence\n");
            return NULL;
        }
    }

    return match_;
}
