#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("Empty/Full methods") {
    uint32_t log2_side = get_random_uint(1, 10);
    uint32_t side = 1ULL << log2_side;
    piece p = create_test_piece<piece>(side, 10, {});
    CHECK(p.empty());
    CHECK_FALSE(p.full());

    for (uint32_t i = 0; i != p.side(); ++i) {
        for (uint32_t j = 0; j != p.side(); ++j) p(i, j) = true;
    }
    CHECK_FALSE(p.empty());
    CHECK(p.full());
}

TEST_CASE("Empty/Full method with sub-grid") {
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
    piece p = create_test_piece<piece>(side, 5, filled_cells);
    pel_2425::piece correct_p =
        create_test_piece<pel_2425::piece>(side, 5, filled_cells);

    // p.print_ascii_art(std::cout);
    // correct_p.print_ascii_art(std::cout);

    CHECK(p.empty() == correct_p.empty());
    CHECK(p.full() == correct_p.full());

    const uint64_t num_tests = 10;
    for (uint64_t t = 0; t != num_tests; ++t) {
        uint64_t k = t % num_cells;
        uint64_t subside = 1ULL << get_random_uint(1, 4);
        uint64_t i = filled_cells[k].first;
        uint64_t j = filled_cells[k].second;
        assert(i < side and j < side);
        if (i + subside > side or j + subside > side) {
            bool thrown = false;
            try {
                p.empty(i, j, subside);
            } catch (tetris_exception const& /*e*/) { thrown = true; }
            if (!thrown) {
                REQUIRE_MESSAGE(false,
                                "ERROR --> exception not thrown on "
                                "out-of-bounds call to piece::empty");
            }
            // always have the same number of assertions
            // even when we throw an exception
            CHECK(true);
            CHECK(true);
        } else {
            CHECK(p.empty(i, j, subside) == correct_p.empty(i, j, subside));
            CHECK(p.full(i, j, subside) == correct_p.full(i, j, subside));
        }
    }
}

TEST_CASE("rotate") {
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
    piece p = create_test_piece<piece>(side, 5, filled_cells);
    pel_2425::piece correct_p =
        create_test_piece<pel_2425::piece>(side, 5, filled_cells);

    const uint64_t num_tests = 10;
    for (uint64_t t = 0; t != num_tests; ++t) {
        p.rotate();
        correct_p.rotate();
        bool equal = equal_pieces(p, correct_p);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> invalid piece after rotation");
    }
}

TEST_CASE("cut row") {
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
    piece p = create_test_piece<piece>(side, 5, filled_cells);
    pel_2425::piece correct_p =
        create_test_piece<pel_2425::piece>(side, 5, filled_cells);

    const uint64_t num_tests = 10;
    for (uint64_t t = 0; t != num_tests; ++t) {
        uint64_t i = distr(gen);
        p.cut_row(i);
        correct_p.cut_row(i);
        bool equal = equal_pieces(p, correct_p);
        REQUIRE_MESSAGE(equal == true, "ERROR --> invalid piece after cut_row");

        bool thrown = false;
        try {
            p.cut_row(i + side);
        } catch (tetris_exception const& /*e*/) { thrown = true; }
        if (!thrown) {
            REQUIRE_MESSAGE(false,
                            "ERROR --> exception not thrown in out-of-bounds "
                            "call to cut_row");
        }
    }
}