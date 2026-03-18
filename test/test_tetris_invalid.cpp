#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("invalid tetris A") {  // one dimension missing
    std::string path(data_path + "invalid_tetris_0.txt");
    std::ifstream in(path);
    check_if_found(in);
    tetris t;
    bool thrown = false;
    try {
        in >> t;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(thrown == true,
                    "ERROR --> exception not thrown in tetris::operator>> "
                    "while reading invalid file format");
}

TEST_CASE("invalid tetris B") {  // one dimension 0
    std::string path(data_path + "invalid_tetris_1.txt");
    std::ifstream in(path);
    check_if_found(in);
    tetris t;
    bool thrown = false;
    try {
        in >> t;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(thrown == true,
                    "ERROR --> exception not thrown in tetris::operator>> "
                    "while reading invalid file format");
}

TEST_CASE("invalid tetris C") {  // missing x-coordinate for a piece
    std::string path(data_path + "invalid_tetris_2.txt");
    std::ifstream in(path);
    check_if_found(in);
    tetris t;
    bool thrown = false;
    try {
        in >> t;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(thrown == true,
                    "ERROR --> exception not thrown in tetris::operator>> "
                    "while reading invalid file format");
}

TEST_CASE("invalid tetris D") {  // error in grid's format for a piece
    std::string path(data_path + "invalid_tetris_3.txt");
    std::ifstream in(path);
    check_if_found(in);
    tetris t;
    bool thrown = false;
    try {
        in >> t;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(thrown == true,
                    "ERROR --> exception not thrown in tetris::operator>> "
                    "while reading invalid file format");
}

TEST_CASE("invalid tetris E") {  // one piece cannot be contained
    std::string path(data_path + "invalid_tetris_4.txt");
    std::ifstream in(path);
    check_if_found(in);
    tetris t;
    bool thrown = false;
    try {
        in >> t;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(thrown == true,
                    "ERROR --> exception not thrown in tetris::operator>> "
                    "while reading invalid file format");
}
