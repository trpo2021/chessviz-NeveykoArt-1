#include "libchessviz/chess.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("./exe file_move\n");
        return -1;
    }

    char chess[8][8];
    createChess(chess);

    FILE* file_moves = fopen(argv[1], "r");
    int count_moves;

    match *match_ = Read_file(file_moves, &count_moves);
    if (match_ == NULL) {
      printf("Error: wrong input\n");
      return -1;
    }

    visualizationChess(chess, match_, count_moves);

    free(match_);
    fclose(file_moves);
    return 0;
}
