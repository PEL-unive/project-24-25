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
        tetris t1;
        tetris t2;
        CHECK(t2 == t1);
    }
    try {
        std::string path = data_path + "game3.txt";
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

        tetris t2_copy(t2);
        CHECK(t2_copy == t2);
        CHECK(equal_tetris(t2_copy, t1));
        CHECK(equal_tetris_non_const(t2_copy, t1));

        path = data_path + "game0.txt";
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
        equal = equal_tetris(t1, t2);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");
        equal = equal_tetris_non_const(t1, t2);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");

        t2_copy = t2;
        CHECK(t2_copy == t2);
        CHECK(equal_tetris(t2_copy, t1));
        CHECK(equal_tetris_non_const(t2_copy, t1));
    } catch (tetris_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected tetris_exception thrown: "
                                   << e.what());
    }
}