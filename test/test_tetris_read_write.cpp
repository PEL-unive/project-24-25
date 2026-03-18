#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("tetris::operator>> and tetris::operator<< 1") {
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
        bool equal = equal_tetris(t, correct_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> tetris field not loaded correctly");

        std::ostringstream oss_t;
        std::ostringstream oss_correct_t;
        oss_t << t;
        oss_correct_t << correct_t;
        std::string result_t = oss_t.str();
        std::string result_correct_t = oss_correct_t.str();
        std::istringstream iss_t(result_t);
        std::istringstream iss_correct_t(result_correct_t);
        tetris another_t;
        pel_2425::tetris another_correct_t;
        iss_t >> another_t;
        iss_correct_t >> another_correct_t;
        equal = equal_tetris(another_t, another_correct_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> tetris field not loaded or saved correctly "
                        "to/from stream");
    }
}

TEST_CASE("tetris::operator>> and tetris::operator<< 2") {
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
        bool equal = equal_tetris(t, correct_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> tetris field not loaded correctly");

        std::ostringstream oss_t;
        std::ostringstream oss_correct_t;
        oss_t << t;
        oss_correct_t << correct_t;
        std::string result_t = oss_t.str();
        std::string result_correct_t = oss_correct_t.str();
        std::istringstream iss_t(result_t);
        std::istringstream iss_correct_t(result_correct_t);
        tetris another_t;
        pel_2425::tetris another_correct_t;
        iss_t >> another_t;
        iss_correct_t >> another_correct_t;
        equal = equal_tetris(another_t, another_correct_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> tetris field not loaded or saved correctly "
                        "to/from stream");
    }
}

TEST_CASE("tetris::operator>> and tetris::operator<< 3") {
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
        bool equal = equal_tetris(t, correct_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> tetris field not loaded correctly");

        std::ostringstream oss_t;
        std::ostringstream oss_correct_t;
        oss_t << t;
        oss_correct_t << correct_t;
        std::string result_t = oss_t.str();
        std::string result_correct_t = oss_correct_t.str();
        std::istringstream iss_t(result_t);
        std::istringstream iss_correct_t(result_correct_t);
        tetris another_t;
        pel_2425::tetris another_correct_t;
        iss_t >> another_t;
        iss_correct_t >> another_correct_t;
        equal = equal_tetris(another_t, another_correct_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> tetris field not loaded or saved correctly "
                        "to/from stream");
    }
}