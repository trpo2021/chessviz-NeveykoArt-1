#pragma once
#include "motion.h"

bool _move(motion the_motion, char chess[8][8]);
void print_the_motion(motion the_motion);
void printChess(char chess[8][8]);
void createChess(char chess[8][8]);
motion initMotion();
