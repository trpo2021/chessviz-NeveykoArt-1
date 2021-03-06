#include "../src/libchessviz/chess.h"
#include "ctest.h"
#include <stdlib.h>
// there are many different ASSERT macro's (see ctest.h)

CTEST(moveK, king_test1)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2-e3 Ke8-e7";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveK(match_.white_motion, chess));
    ASSERT_TRUE(moveK(match_.black_motion, chess));
}

CTEST(moveK, king_test2)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2-d2 Ke7-f7";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveK(match_.white_motion, chess));
    ASSERT_TRUE(moveK(match_.black_motion, chess));
}

CTEST(moveK, king_test3)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2-d3 Ke7-f6";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveK(match_.white_motion, chess));
    ASSERT_TRUE(moveK(match_.black_motion, chess));
}

CTEST(moveK, king_test4)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2-d1 Ke7-f8";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveK(match_.white_motion, chess));
    ASSERT_TRUE(moveK(match_.black_motion, chess));
}

CTEST(moveK, king_test5)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2xd1 Ke7xf8";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[7][3] = 'p';
    chess[1][5] = 'P';

    ASSERT_TRUE(moveK(match_.white_motion, chess));
    ASSERT_TRUE(moveK(match_.black_motion, chess));
}

CTEST(moveK, king_test6)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2-g3 Ke8-c2";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_FALSE(moveK(match_.white_motion, chess));
    ASSERT_FALSE(moveK(match_.black_motion, chess));
}

CTEST(moveK, king_test7)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2xd1 Kd1xe2";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[7][3] = 'k';
    chess[6][4] = 'K';

    ASSERT_FALSE(moveK(match_.white_motion, chess));
    ASSERT_FALSE(moveK(match_.black_motion, chess));
}

CTEST(moveK, king_test8)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2xd1 Ke7xf8";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[7][3] = 'P';
    chess[0][5] = 'p';

    ASSERT_FALSE(moveK(match_.white_motion, chess));
    ASSERT_FALSE(moveK(match_.black_motion, chess));
}

CTEST(moveK, king_test9)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2xd1#";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[7][3] = 'q';

    ASSERT_TRUE(moveK(match_.white_motion, chess));
}

CTEST(moveK, king_test10)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ke2-d1 Ke7xf8#";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[0][5] = 'P';

    ASSERT_TRUE(moveK(match_.white_motion, chess));
    ASSERT_TRUE(moveK(match_.black_motion, chess));
}
