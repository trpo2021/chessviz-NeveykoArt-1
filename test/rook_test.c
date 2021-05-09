#include "../src/libchessviz/chess.h"
#include "ctest.h"
#include <stdlib.h>

// there are many different ASSERT macro's (see ctest.h)

CTEST(moveR, rook_test1)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Re2-e4 Re6-e5";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveR(match_.white_motion, chess));
    ASSERT_TRUE(moveR(match_.black_motion, chess));
}

CTEST(moveR, rook_test2)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Re2-f3 Re6-d7";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_FALSE(moveR(match_.white_motion, chess));
    ASSERT_FALSE(moveR(match_.black_motion, chess));
}

CTEST(moveR, rook_test3)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ra1-a8 Re8-e1";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[5][0] = 'P';
    chess[4][4] = 'P';

    ASSERT_FALSE(moveR(match_.white_motion, chess));
    ASSERT_FALSE(moveR(match_.black_motion, chess));
}

CTEST(moveR, rook_test4)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1.  Ra1xa8 Re8xe1";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[5][0] = 'k';
    chess[4][4] = 'K';

    ASSERT_FALSE(moveR(match_.white_motion, chess));
    ASSERT_FALSE(moveR(match_.black_motion, chess));
}

CTEST(moveR, rook_test5)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1.  Ra1-a8 Re8-e1";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[5][0] = 'k';
    chess[4][4] = 'K';

    ASSERT_FALSE(moveR(match_.white_motion, chess));
    ASSERT_FALSE(moveR(match_.black_motion, chess));
}

CTEST(moveR, rook_test6)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ra1xa8 Re8xe1";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[0][0] = 'P';
    chess[7][4] = 'p';

    ASSERT_FALSE(moveR(match_.white_motion, chess));
    ASSERT_FALSE(moveR(match_.black_motion, chess));
}

CTEST(moveR, rook_test7)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Re2-e3#";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveR(match_.white_motion, chess));
}

CTEST(moveR, rook_test8)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ra1-h1 Re2-e5";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveR(match_.white_motion, chess));
    ASSERT_TRUE(moveR(match_.black_motion, chess));
}

CTEST(moveR, rook_test9)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Rh1-a1 Re5-e2";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);

    ASSERT_TRUE(moveR(match_.white_motion, chess));
    ASSERT_TRUE(moveR(match_.black_motion, chess));
}

CTEST(moveR, rook_test10)
{
    match match_ = initMatch();

    char chess[8][8];

    char line[] = "1. Ra1xa5 Re5xb5";

    ASSERT_TRUE(checkLine(line, &match_));
    testPrint(chess, match_);
    chess[3][0] = 'p';
    chess[3][1] = 'P';

    ASSERT_TRUE(moveR(match_.white_motion, chess));
    ASSERT_TRUE(moveR(match_.black_motion, chess));
}
