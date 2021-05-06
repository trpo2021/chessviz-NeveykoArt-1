#include "../src/libchessviz/chess.h"
#include "ctest.h"
#include <stdlib.h>

// there are many different ASSERT macro's (see ctest.h)

CTEST(checkMove, test1)
{
    motion the_motion = initMotion();

    ASSERT_TRUE(checkMove(" 0-0 ", &the_motion));
    ASSERT_EQUAL(Short, the_motion.castling);
}

CTEST(checkMove, test2)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove(" 0-0-0 ", &the_motion));
    ASSERT_EQUAL(Long, the_motion.castling);
}

CTEST(checkMove, test3)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("Be2-d3", &the_motion));
    ASSERT_EQUAL('B', the_motion.figure);
    ASSERT_EQUAL(false, the_motion.type_motion);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(3, the_motion.end_position_x);
    ASSERT_EQUAL(5, the_motion.end_position_y);
}

CTEST(checkMove, test4)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("Be2xe4", &the_motion));
    ASSERT_EQUAL('B', the_motion.figure);
    ASSERT_EQUAL(true, the_motion.type_motion);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
}

CTEST(checkMove, test5)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2xe4e.p.", &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(true, the_motion.type_motion);
    ASSERT_EQUAL(true, the_motion.flag_ep);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
}

CTEST(checkMove, test6)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4+", &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(false, the_motion.type_motion);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
    ASSERT_EQUAL(true, the_motion.flag_shah);
}

CTEST(checkMove, test7)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2xe4#", &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(true, the_motion.type_motion);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
    ASSERT_EQUAL(true, the_motion.flag_cmate);
}

CTEST(checkMove, test8)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4N", &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(false, the_motion.type_motion);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
    ASSERT_EQUAL(true, the_motion.flag_transformation);
    ASSERT_EQUAL('N', the_motion.transformation_figure);
}

CTEST(checkMove, test9)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("Gl9mm9", &the_motion));
}

CTEST(checkMove, test10)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("0-0-0-0", &the_motion));
}

CTEST(checkMove, test11)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("Be2-e4L", &the_motion));
}

CTEST(checkMove, test12)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("B", &the_motion));
}

CTEST(checkMove, test13)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("AAAA", &the_motion));
}

CTEST(checkMove, test14)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("0-0", &the_motion));
}

CTEST(checkMove, test15)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("e", &the_motion));
}

CTEST(checkMove, test16)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("e2", &the_motion));
}

CTEST(checkMove, test17)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("e2-", &the_motion));
}

CTEST(checkMove, test18)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("e2-et", &the_motion));
}

CTEST(checkMove, test19)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4", &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(false, the_motion.type_motion);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
}

CTEST(checkMove, test20)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("e2-e4e", &the_motion));
}

CTEST(checkMove, test21)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2xe4B#", &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(true, the_motion.type_motion);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
    ASSERT_EQUAL(true, the_motion.flag_cmate);
    ASSERT_EQUAL(true, the_motion.flag_transformation);
    ASSERT_EQUAL('B', the_motion.transformation_figure);
}

CTEST(checkMove, test22)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2xe4e.p.#", &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(true, the_motion.type_motion);
    ASSERT_EQUAL(true, the_motion.flag_ep);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
    ASSERT_EQUAL(true, the_motion.flag_cmate);
}

CTEST(checkMove, test23)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2xe4e.p.+", &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(true, the_motion.type_motion);
    ASSERT_EQUAL(true, the_motion.flag_ep);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
    ASSERT_EQUAL(true, the_motion.flag_shah);
}

CTEST(checkMove, test24)
{
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4B+", &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(false, the_motion.type_motion);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
    ASSERT_EQUAL(true, the_motion.flag_shah);
    ASSERT_EQUAL(true, the_motion.flag_transformation);
    ASSERT_EQUAL('B', the_motion.transformation_figure);
}

CTEST(checkMove, test25)
{
    motion the_motion = initMotion();
    char *move = malloc(6 * sizeof(char));

    move[0] = 'e';
    move[1] = '2';
    move[2] = '-';
    move[3] = 'e';
    move[4] = '4';
    move[5] = '\0';

    ASSERT_TRUE(checkMove(move, &the_motion));
    ASSERT_EQUAL('P', the_motion.figure);
    ASSERT_EQUAL(false, the_motion.type_motion);
    ASSERT_EQUAL(4, the_motion.start_position_x);
    ASSERT_EQUAL(6, the_motion.start_position_y);
    ASSERT_EQUAL(4, the_motion.end_position_x);
    ASSERT_EQUAL(4, the_motion.end_position_y);
    free(move);
}

CTEST(checkMove, test26)
{
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("e0-e0", &the_motion));
}
