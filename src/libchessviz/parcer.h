#pragma once
#include "motion.h"

bool checkMove(char* move, motion* the_motion);
bool checkLine(char* line, match* match_);
match* Read_file(FILE* file_moves, int* count_moves);
int atoi_new(char* id_move);
