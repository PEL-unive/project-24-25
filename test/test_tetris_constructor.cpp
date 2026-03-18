#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("Valid constructor 1") {
    tetris t;
    CHECK(t.score() == 0);
    CHECK(t.width() == 0);
    CHECK(t.height() == 0);
}

TEST_CASE("Valid constructor 2") {
    uint32_t w = get_random_uint(1, 100);
    uint32_t h = get_random_uint(1, 100);
    tetris t(w, h);
    CHECK(t.score() == 0);
    CHECK(t.width() == w);
    CHECK(t.height() == h);
}

TEST_CASE("Valid constructor 3") {
    uint32_t w = get_random_uint(1, 100);
    uint32_t h = get_random_uint(1, 100);
    uint32_t s = get_random_uint(1, 100);
    tetris t(w, h, s);
    CHECK(t.score() == s);
    CHECK(t.width() == w);
    CHECK(t.height() == h);
}

TEST_CASE("Invalid constructor 1") {
    bool thrown = false;
    try {
        tetris t(0, get_random_uint(1, 100));
    } catch (tetris_exception const& /*e*/) { thrown = true; }
    if (!thrown) REQUIRE_MESSAGE(false, "ERROR --> exception not thrown");
}

TEST_CASE("Invalid constructor 2") {
    bool thrown = false;
    try {
        tetris t(get_random_uint(1, 100), 0);
    } catch (tetris_exception const& /*e*/) { thrown = true; }
    if (!thrown) REQUIRE_MESSAGE(false, "ERROR --> exception not thrown");
}

TEST_CASE("Invalid constructor 3") {
    bool thrown = false;
    try {
        tetris t(0, 0);
    } catch (tetris_exception const& /*e*/) { thrown = true; }
    if (!thrown) REQUIRE_MESSAGE(false, "ERROR --> exception not thrown");
}