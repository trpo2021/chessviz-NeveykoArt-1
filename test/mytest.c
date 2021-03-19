#include <stdlib.h>
#include "ctest.h"
#include "../src/libchessviz/chess.h"


// there are many different ASSERT macro's (see ctest.h)
CTEST(checkMove, test1) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4", &the_motion, White));
}

CTEST(checkMove, test2) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("Re2-e4", &the_motion, White));
}

CTEST(checkMove, test3) {
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("e0-e4R", &the_motion, White));
}

CTEST(checkMove, test4) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4+", &the_motion, White));
}

CTEST(checkMove, test5) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4#", &the_motion, White));
}

CTEST(checkMove, test6) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4e.p.", &the_motion, White));
}

CTEST(checkMove, test7) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4e.p.+", &the_motion, White));
}

CTEST(checkMove, test8) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e2-e4R", &the_motion, White));
}

CTEST(checkMove, test9) {
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("Re2-e4R", &the_motion, White));
}

CTEST(checkMove, test10) {
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("e2-e4+#", &the_motion, White));
}

CTEST(checkMove, test11) {
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("Re2-e4e.p.", &the_motion, White));
}

CTEST(checkMove, test12) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("0-0", &the_motion, White));
}

CTEST(checkMove, test13) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("0-0-0", &the_motion, White));
}

CTEST(checkMove, test14) {
    motion the_motion = initMotion();
    ASSERT_FALSE(checkMove("e2-e4e.p", &the_motion, White));
}

CTEST(checkMove, test15) {
    motion the_motion = initMotion();
    ASSERT_TRUE(checkMove("e7-e5", &the_motion, Black));
}