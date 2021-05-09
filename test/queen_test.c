#include "../src/libchessviz/chess.h"
#include "ctest.h"
#include <stdlib.h>

// there are many different ASSERT macro's (see ctest.h)

CTEST(moveQ, queen_test1)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qe2-e4 Qe6-e5";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveQ(match_.white_motion, chess));
    ASSERT_TRUE(moveQ(match_.black_motion, chess));
}

CTEST(moveQ, queen_test2)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qe2-f3 Qe4-d5";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveQ(match_.white_motion, chess));
    ASSERT_TRUE(moveQ(match_.black_motion, chess));
}

CTEST(moveQ, queen_test3)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qe2xf3 Qe4-d5";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_FALSE(moveQ(match_.white_motion, chess));
    ASSERT_TRUE(moveQ(match_.black_motion, chess));
}

CTEST(moveQ, queen_test4)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qe2-e3#";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveQ(match_.white_motion, chess));
}

CTEST(moveQ, queen_test5)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qe2xg4 Qe4xb7";
    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[4][6] = 'P';
    chess[1][1] = 'p';

    ASSERT_FALSE(moveQ(match_.white_motion, chess));
    ASSERT_FALSE(moveQ(match_.black_motion, chess));
}

CTEST(moveQ, queen_test6)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qe2-a8 Qe4-h6";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_FALSE(moveQ(match_.white_motion, chess));
    ASSERT_FALSE(moveQ(match_.black_motion, chess));
}

CTEST(moveQ, queen_test7)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qe2-a4 Qe6-a7";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_FALSE(moveQ(match_.white_motion, chess));
    ASSERT_FALSE(moveQ(match_.black_motion, chess));
}

CTEST(moveQ, queen_test8)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qh1-a1 Qe5-e2";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveQ(match_.white_motion, chess));
    ASSERT_TRUE(moveQ(match_.black_motion, chess));
}

CTEST(moveQ, queen_test9)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qh1-a8 Qe5-h8";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveQ(match_.white_motion, chess));
    ASSERT_TRUE(moveQ(match_.black_motion, chess));
}

CTEST(moveQ, queen_test10)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Qh1-a8+ Qe5-a8";
    ASSERT_TRUE(checkLine(line, &match_));

    testPrint(chess, match_);

    ASSERT_TRUE(moveQ(match_.white_motion, chess));
    ASSERT_FALSE(moveQ(match_.black_motion, chess));
}
