#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("Move constructor/assignment") {
    const uint64_t num_cells = 20;
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
    piece p1_copy = p1;
    piece p2(std::move(p1));
    CHECK(p2 == p1_copy);

    piece p2_copy = p2;
    p1_copy = std::move(p2);
    CHECK(p1_copy == p2_copy);
}