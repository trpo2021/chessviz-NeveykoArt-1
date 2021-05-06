#include "../src/libchessviz/chess.h"
#include "ctest.h"
#include <stdlib.h>

// there are many different ASSERT macro's (see ctest.h)

CTEST(moveN, knight_test1)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Ne2-e4 Ne6-e5";

    ASSERT_TRUE(checkLine(line, &match_));

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveN(match_.white_motion, chess));
    ASSERT_FALSE(moveN(match_.black_motion, chess));
}

CTEST(moveN, knight_test2)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Ne2-f4 Ne6-d4";

    ASSERT_TRUE(checkLine(line, &match_));

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveN(match_.white_motion, chess));
    ASSERT_TRUE(moveN(match_.black_motion, chess));
}

CTEST(moveN, knight_test3)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Ne2-g4 Ne6-a5";

    ASSERT_TRUE(checkLine(line, &match_));

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveN(match_.white_motion, chess));
    ASSERT_FALSE(moveN(match_.black_motion, chess));
}

CTEST(moveN, knight_test4)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Ne2xf4 Ne4xf6";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[2][5] = 'k';
    chess[4][5] = 'K';
    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveN(match_.white_motion, chess));
    ASSERT_FALSE(moveN(match_.black_motion, chess));
}

CTEST(moveN, knight_test5)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Ne2-e4 Ne6-e5";

    ASSERT_TRUE(checkLine(line, &match_));

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveN(match_.white_motion, chess));
    ASSERT_FALSE(moveN(match_.black_motion, chess));
}

CTEST(moveN, knight_test6)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Na1xb3 Na8xb6";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[5][1] = 'P';
    chess[2][1] = 'p';
    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveN(match_.white_motion, chess));
    ASSERT_FALSE(moveN(match_.black_motion, chess));
}

CTEST(moveN, knight_test7)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Ne2-f4#";

    ASSERT_TRUE(checkLine(line, &match_));

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveN(match_.white_motion, chess));
}

CTEST(moveN, knight_test8)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Ne2-f4+ Ne5-d7";

    ASSERT_TRUE(checkLine(line, &match_));

    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveN(match_.white_motion, chess));
    ASSERT_TRUE(moveN(match_.black_motion, chess));
}

CTEST(moveN, knight_test9)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Na1-b3 Na8-b6";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[6][1] = 'p';
    chess[1][1] = 'P';
    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_TRUE(moveN(match_.white_motion, chess));
    ASSERT_TRUE(moveN(match_.black_motion, chess));
}

CTEST(moveN, knight_test10)
{
    match match_ = initMatch();

    char chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }

    char line[] = "1. Na8xb3 Na1xb6";

    ASSERT_TRUE(checkLine(line, &match_));
    chess[5][1] = 'p';
    chess[2][1] = 'P';
    chess[match_.white_motion.start_position_y]
         [match_.white_motion.start_position_x]
            = match_.white_motion.figure;
    chess[match_.black_motion.start_position_y]
         [match_.black_motion.start_position_x]
            = tolower(match_.black_motion.figure);

    ASSERT_FALSE(moveN(match_.white_motion, chess));
    ASSERT_FALSE(moveN(match_.black_motion, chess));
}
