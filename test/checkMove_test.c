#include "../src/libchessviz/chess.h"
#include "ctest.h"
#include <stdlib.h>

// there are many different ASSERT macro's (see ctest.h)
CTEST(checkMove, test1)
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
