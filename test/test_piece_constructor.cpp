#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("Valid constructor") {
    piece p;
    CHECK(p.side() == 0);
    CHECK(p.color() == 0);
    CHECK(p.empty() == true);
    CHECK(p.full() == false);
}

TEST_CASE("Valid constructor") {
    uint32_t log2_side = get_random_uint(0, 10);
    uint32_t side = 1ULL << log2_side;
    uint32_t color = get_random_uint(1, 255);
    piece p(side, color);
    CHECK(p.side() == side);
    CHECK(p.color() == color);
    CHECK(p.empty() == true);
    CHECK(p.full() == false);
}

TEST_CASE("Invalid constructor") {
    /*
        Note: we cannot just do
        CHECK_THROWS_AS(piece(0, 5), tetris_exception);
        because this prints the test!
    */
    bool thrown = false;
    try {
        piece p(0, 5);
    } catch (tetris_exception const& /*e*/) { thrown = true; }
    if (!thrown) REQUIRE_MESSAGE(false, "ERROR --> exception not thrown");
}

TEST_CASE("Invalid constructor") {
    uint32_t log2_side = get_random_uint(1, 10);
    uint32_t side = 1ULL << log2_side;
    side += 1;  // not a power of two
    bool thrown = false;
    try {
        piece p(side, 5);
    } catch (tetris_exception const& /*e*/) { thrown = true; }
    if (!thrown) REQUIRE_MESSAGE(false, "ERROR --> exception not thrown");
}

TEST_CASE("Invalid constructor") {
    bool thrown = false;
    try {
        piece p(8, 0);
    } catch (tetris_exception const& /*e*/) { thrown = true; }
    if (!thrown) REQUIRE_MESSAGE(false, "ERROR --> exception not thrown");
}
