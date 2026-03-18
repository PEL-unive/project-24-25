#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("tetris::operator>> 1") {
    std::string path(data_path + "tetris0.txt");
    std::ifstream in1(path);
    check_if_found(in1);
    std::ifstream in2(path);
    check_if_found(in2);
    while (in1 and in2) {
        tetris t;
        pel_2425::tetris correct_t;
        in1 >> t;
        in2 >> correct_t;
        // t.print_ascii_art(std::cout);
        // correct_t.print_ascii_art(std::cout);
        bool equal = equal_tetris(t, correct_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> tetris field not loaded correctly");
    }
}

TEST_CASE("tetris::operator>> 2") {
    std::string path(data_path + "tetris1.txt");
    std::ifstream in1(path);
    check_if_found(in1);
    std::ifstream in2(path);
    check_if_found(in2);
    while (in1 and in2) {
        tetris t;
        pel_2425::tetris correct_t;
        in1 >> t;
        in2 >> correct_t;
        // t.print_ascii_art(std::cout);
        // correct_t.print_ascii_art(std::cout);
        bool equal = equal_tetris(t, correct_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> tetris field not loaded correctly");
    }
}

TEST_CASE("tetris::operator>> 3") {
    std::string path(data_path + "tetris2.txt");
    std::ifstream in1(path);
    check_if_found(in1);
    std::ifstream in2(path);
    check_if_found(in2);
    while (in1 and in2) {
        tetris t;
        pel_2425::tetris correct_t;
        in1 >> t;
        in2 >> correct_t;
        // t.print_ascii_art(std::cout);
        // correct_t.print_ascii_art(std::cout);
        bool equal = equal_tetris(t, correct_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> tetris field not loaded correctly");
    }
}