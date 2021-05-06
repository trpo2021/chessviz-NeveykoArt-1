#pragma once
#include "motion.h"

bool _move(motion the_motion, char chess[8][8]);
void printChess(char chess[8][8]);
void createChess(char chess[8][8]);
void visualizationChess(char chess[8][8], match* match_, int count_moves);
motion initMotion();
match initMatch();
