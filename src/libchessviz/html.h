#pragma once
#include "motion.h"

void addStartHTML(FILE* file);
void addEndHTML(FILE* file);
void addChessHTML(FILE* file, char chess[8][8], char* move);
