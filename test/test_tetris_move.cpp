#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("Move constructor/assignment") {
    try {
        std::string path = data_path + "game1.txt";
        pel_2425::tetris t1;
        tetris t2;
        {
            std::ifstream ifs(path);
            check_if_found(ifs);
            play<pel_2425::piece, pel_2425::tetris>(ifs, t1);
        }
        {
            std::ifstream ifs(path);
            check_if_found(ifs);
            play<piece, tetris>(ifs, t2);
        }
        bool equal = equal_tetris(t1, t2);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");
        equal = equal_tetris_non_const(t1, t2);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");

        tetris t2_moved(std::move(t2));
        CHECK(equal_tetris(t2_moved, t1));
        CHECK(equal_tetris_non_const(t2_moved, t1));
        CHECK(t2_moved != t2);

        path = data_path + "game2.txt";
        {
            std::ifstream ifs(path);
            check_if_found(ifs);
            play<pel_2425::piece, pel_2425::tetris>(ifs, t1);
        }
        {
            std::ifstream ifs(path);
            check_if_found(ifs);
            play<piece, tetris>(ifs, t2_moved);
        }
        equal = equal_tetris(t1, t2_moved);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");
        equal = equal_tetris_non_const(t1, t2_moved);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");

        tetris t3;
        tetris t2_copy = t2_moved;
        t3 = std::move(t2_moved);
        CHECK(t3 == t2_copy);
        CHECK(t3 != t2_moved);
        CHECK(equal_tetris(t3, t1));
        CHECK(equal_tetris_non_const(t3, t1));
    } catch (tetris_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected tetris_exception thrown: "
                                   << e.what());
    }
}