#include "../src/libchessviz/chess.h"
#include "ctest.h"
#include <stdlib.h>

// there are many different ASSERT macro's (see ctest.h)

CTEST(moveP, pawn_test1)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. e2-e4 e7-e5";

    ASSERT_TRUE(checkLine(line, &match_));

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveP(match_.white_motion, chess));
    ASSERT_TRUE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test2)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. e4xd5 e7-e5";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[3][3] = 'p';

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveP(match_.white_motion, chess));
    ASSERT_TRUE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test3)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. e7-e8R e2-e1Q";

    ASSERT_TRUE(checkLine(line, &match_));


    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveP(match_.white_motion, chess));
    ASSERT_TRUE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test4)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. e6-e7#";

    ASSERT_TRUE(checkLine(line, &match_));


    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveP(match_.white_motion, chess));
}

CTEST(moveP, pawn_test5)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. e6-e7+ e3-e2";

    ASSERT_TRUE(checkLine(line, &match_));


    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveP(match_.white_motion, chess));
    ASSERT_TRUE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test6)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. e6-a8 e3-g7";

    ASSERT_TRUE(checkLine(line, &match_));


    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveP(match_.white_motion, chess));
    ASSERT_FALSE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test7)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. d5xe6e.p. c7-c5";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[3][4] = 'p';

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveP(match_.white_motion, chess));
    ASSERT_TRUE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test8)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. e2-e4 e7-e5";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[5][4] = 'n';
    chess[2][4] = 'n';
    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveP(match_.white_motion, chess));
    ASSERT_FALSE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test9)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. d5xe6e.p. c7-c5";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[3][4] = 'P';

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveP(match_.white_motion, chess));
    ASSERT_TRUE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test10)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. e2-e4 e7-e5";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[4][4] = 'n';
    chess[3][4] = 'n';
    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveP(match_.white_motion, chess));
    ASSERT_FALSE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test11)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. d5xe6 c7-c5";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[2][4] = 'N';

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveP(match_.white_motion, chess));
    ASSERT_TRUE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test12)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. d5xe6 c7-c5";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[2][4] = 'P';

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveP(match_.white_motion, chess));
    ASSERT_TRUE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test13)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. d5xe6 c7-c5";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[2][4] = 'K';

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveP(match_.white_motion, chess));
    ASSERT_TRUE(moveP(match_.black_motion, chess));
}

CTEST(moveP, pawn_test14)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. e2-e5 e7-e4";

    ASSERT_TRUE(checkLine(line, &match_));

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveP(match_.white_motion, chess));
    ASSERT_FALSE(moveP(match_.black_motion, chess));
}
