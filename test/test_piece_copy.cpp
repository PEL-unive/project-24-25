#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("Copy constructor/assignment") {
    {
        piece p1;
        piece p2;
        CHECK(p2 == p1);
    }

    const uint64_t num_cells = 50;
    uint32_t log2_side = get_random_uint(1, 10);
    uint32_t side = 1ULL << log2_side;

    std::uniform_int_distribution<uint64_t> distr(0, side - 1);
    std::default_random_engine gen(time(NULL));  // randomize

    std::vector<std::pair<uint32_t, uint32_t>> filled_cells;
    filled_cells.reserve(num_cells);
    for (uint64_t i = 0; i != num_cells; ++i) {
        filled_cells.push_back({distr(gen), distr(gen)});
    }
    piece p1 = create_test_piece<piece>(side, 5, filled_cells);
    piece p2(p1);
    CHECK(p2 == p1);

    p2(filled_cells.front().first, filled_cells.front().second) = false;
    CHECK(p2 != p1);

    p1 = p2;
    CHECK(p1 == p2);
}