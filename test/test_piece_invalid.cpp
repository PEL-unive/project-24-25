#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("invalid piece 0") {
    std::string path(data_path + "invalid_piece_0.txt");
    std::ifstream in(path);
    check_if_found(in);
    piece p;
    bool thrown = false;
    try {
        in >> p;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(
        thrown == true,
        "ERROR --> exception not thrown on loading invalid piece format");
}

TEST_CASE("invalid piece 1") {
    std::string path(data_path + "invalid_piece_1.txt");
    std::ifstream in(path);
    check_if_found(in);
    piece p;
    bool thrown = false;
    try {
        in >> p;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(
        thrown == true,
        "ERROR --> exception not thrown on loading invalid piece format");
}

TEST_CASE("invalid piece 2") {
    std::string path(data_path + "invalid_piece_2.txt");
    std::ifstream in(path);
    check_if_found(in);
    piece p;
    bool thrown = false;
    try {
        in >> p;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(
        thrown == true,
        "ERROR --> exception not thrown on loading invalid piece format");
}

TEST_CASE("invalid piece 3") {
    std::string path(data_path + "invalid_piece_3.txt");
    std::ifstream in(path);
    check_if_found(in);
    piece p;
    bool thrown = false;
    try {
        in >> p;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(
        thrown == true,
        "ERROR --> exception not thrown on loading invalid piece format");
}

TEST_CASE("invalid piece 4") {
    std::string path(data_path + "invalid_piece_4.txt");
    std::ifstream in(path);
    check_if_found(in);
    piece p;
    bool thrown = false;
    try {
        in >> p;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(
        thrown == true,
        "ERROR --> exception not thrown on loading invalid piece format");
}

TEST_CASE("invalid piece 5") {
    std::string path(data_path + "invalid_piece_5.txt");
    std::ifstream in(path);
    check_if_found(in);
    piece p;
    bool thrown = false;
    try {
        in >> p;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(
        thrown == true,
        "ERROR --> exception not thrown on loading invalid piece format");
}

TEST_CASE("invalid piece 6") {
    std::string path(data_path + "invalid_piece_6.txt");
    std::ifstream in(path);
    check_if_found(in);
    piece p;
    bool thrown = false;
    try {
        in >> p;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(
        thrown == true,
        "ERROR --> exception not thrown on loading invalid piece format");
}

TEST_CASE("invalid piece 7") {
    std::string path(data_path + "invalid_piece_7.txt");
    std::ifstream in(path);
    check_if_found(in);
    piece p;
    bool thrown = false;
    try {
        in >> p;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(
        thrown == true,
        "ERROR --> exception not thrown on loading invalid piece format");
}

TEST_CASE("invalid piece 8") {
    std::string path(data_path + "invalid_piece_8.txt");
    std::ifstream in(path);
    check_if_found(in);
    piece p;
    bool thrown = false;
    try {
        in >> p;
    } catch (tetris_exception const& /*e*/) { thrown = true; }

    REQUIRE_MESSAGE(
        thrown == true,
        "ERROR --> exception not thrown on loading invalid piece format");
}
