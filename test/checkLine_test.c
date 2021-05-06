#include "../src/libchessviz/chess.h"
#include "ctest.h"
#include <stdlib.h>

// there are many different ASSERT macro's (see ctest.h)

CTEST(checkLine, test1)
{
    match match_ = initMatch();

    char line[] = "2. e2-e4 Be7-e8";

    ASSERT_TRUE(checkLine(line, &match_));
}

CTEST(checkLine, test2)
{
    match match_ = initMatch();

    char line[] = "AAAAAAAA";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test3)
{
    match match_ = initMatch();

    char line[] = "2... e2-e4 e2-e4";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test4)
{
    match match_ = initMatch();

    char line[] = "2.   e 2-e4  Be7-e8";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test5)
{
    match match_ = initMatch();

    char line[] = "2. e10-e4 Be9-e8";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test6)
{
    match match_ = initMatch();

    char line[] = "22355. e2-e4e.p. Be7-e8";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test7)
{
    match match_ = initMatch();

    char line[] = "1. e2-e4 Be7-e8";

    ASSERT_TRUE(checkLine(line, &match_));
    ASSERT_EQUAL('P', match_.white_motion.figure);
    ASSERT_EQUAL('B', match_.black_motion.figure);
    ASSERT_EQUAL(false, match_.white_motion.type_motion);
    ASSERT_EQUAL(false, match_.black_motion.type_motion);
    ASSERT_EQUAL(4, match_.white_motion.start_position_x);
    ASSERT_EQUAL(6, match_.white_motion.start_position_y);
    ASSERT_EQUAL(4, match_.white_motion.end_position_x);
    ASSERT_EQUAL(4, match_.white_motion.end_position_y);
    ASSERT_EQUAL(4, match_.black_motion.start_position_x);
    ASSERT_EQUAL(1, match_.black_motion.start_position_y);
    ASSERT_EQUAL(4, match_.black_motion.end_position_x);
    ASSERT_EQUAL(0, match_.black_motion.end_position_y);
}

CTEST(checkLine, test8)
{
    match match_ = initMatch();

    char line[] = "20. e2-e4 Be7-e8\n";

    ASSERT_TRUE(checkLine(line, &match_));
    ASSERT_EQUAL('P', match_.white_motion.figure);
    ASSERT_EQUAL('B', match_.black_motion.figure);
    ASSERT_EQUAL(false, match_.white_motion.type_motion);
    ASSERT_EQUAL(false, match_.black_motion.type_motion);
    ASSERT_EQUAL(4, match_.white_motion.start_position_x);
    ASSERT_EQUAL(6, match_.white_motion.start_position_y);
    ASSERT_EQUAL(4, match_.white_motion.end_position_x);
    ASSERT_EQUAL(4, match_.white_motion.end_position_y);
    ASSERT_EQUAL(4, match_.black_motion.start_position_x);
    ASSERT_EQUAL(1, match_.black_motion.start_position_y);
    ASSERT_EQUAL(4, match_.black_motion.end_position_x);
    ASSERT_EQUAL(0, match_.black_motion.end_position_y);
}

CTEST(checkLine, test9)
{
    match match_ = initMatch();

    char line[] = "2. e2-e4 Be7-e8&";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test10)
{
    match match_ = initMatch();

    char line[] = "2. e2-e4 Be7-e8&";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test11)
{
    match match_ = initMatch();

    char line[] = "10. Qe2-e4N Be7-e8";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test12)
{
    match match_ = initMatch();

    char line[] = "10. Qe2xe4#\n";

    ASSERT_TRUE(checkLine(line, &match_));
    ASSERT_EQUAL('Q', match_.white_motion.figure);
    ASSERT_EQUAL(true, match_.white_motion.type_motion);
    ASSERT_EQUAL(4, match_.white_motion.start_position_x);
    ASSERT_EQUAL(6, match_.white_motion.start_position_y);
    ASSERT_EQUAL(4, match_.white_motion.end_position_x);
    ASSERT_EQUAL(4, match_.white_motion.end_position_y);
    ASSERT_EQUAL(true, match_.white_motion.flag_cmate);
}

CTEST(checkLine, test13)
{
    match match_ = initMatch();

    char line[] = "10. #Qe2-e4";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test14)
{
    match match_ = initMatch();

    char line[] = "1 Qe2-e4 Be5-e8";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test15)
{
    match match_ = initMatch();

    char line[] = "1. Qe2-e4 Pe2-e4";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test16)
{
    match match_ = initMatch();

    char line[] = "e2-e4 Qe2-e4";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test17)
{
    match match_ = initMatch();

    char line[] = "Be2-e4 #Qe2-e4";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test18)
{
    match match_ = initMatch();

    char line[] = "10. #Qe-2-e+4";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test19)
{
    match match_ = initMatch();

    char line[] = "-1. Qe2-e4";

    ASSERT_FALSE(checkLine(line, &match_));
}

CTEST(checkLine, test20)
{
    match match_ = initMatch();

    char line[] = "0. Qe2-e4 B";

    ASSERT_FALSE(checkLine(line, &match_));
}
