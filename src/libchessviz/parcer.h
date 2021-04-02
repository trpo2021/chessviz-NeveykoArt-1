#pragma once
#include "motion.h"

bool checkNumberMove(char* number_move);
bool checkPositionMove(char symbol, char number);
bool checkMove(char* move, motion* the_motion, enum BlackWhite color);
