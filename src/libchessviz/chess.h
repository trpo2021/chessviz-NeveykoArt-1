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

//пробел - пустое поле
//большие буквы белые, маленькие черные
// p - пешка
// q - ферзь
// k - король
// b - слон
// n - конь
// r - ладья
//черные сверху

//Пометки, замечания и тд
//Пешка может превратиться в короля?  Good
//Нету превращения пешки + шах / мат

// html.c
void addStartHTML(FILE* file);
void addEndHTML(FILE* file);
void addChessHTML(FILE* file, char chess[8][8], char* move);

// moveFigure.c
bool movePWhite(motion the_motion, char chess[8][8]);
bool movePBlack(motion the_motion, char chess[8][8]);
bool moveB(motion the_motion, char chess[8][8]);
bool moveN(motion the_motion, char chess[8][8]);
bool moveK(motion the_motion, char chess[8][8]);
bool moveQ(motion the_motion, char chess[8][8]);
bool moveR(motion the_motion, char chess[8][8]);

// parcer.c
bool checkNumberMove(char* number_move);
bool checkPositionMove(char symbol, char number);
bool checkMove(char* move, motion* the_motion, enum BlackWhite color);

// game.c
bool _move(motion the_motion, char chess[8][8]);
void print_the_motion(motion the_motion);
void printChess(char chess[8][8]);
void createChess(char chess[8][8]);
motion initMotion();
