#pragma once
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Castling { Without, Short, Long };

enum BlackWhite { Black, White };

typedef struct {
    int start_position_x;
    int end_position_x;

    int start_position_y;
    int end_position_y;

    bool type_motion; //тихий ход - false | взятие - true

    bool flag_shah;
    bool flag_cmate;
    bool flag_ep;
    bool flag_transformation;
    char transformation_figure;

    char figure;
    //фигура, которой ходим
    //большими буквами PQKBNR

    enum BlackWhite color;
    enum Castling castling;

} motion;
