#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE(
    "operator>>: play game A (reading pieces from stream, rotating, and "
    "inserting them in tetris field)") {
    try {
        std::string path = data_path + "game0.txt";
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
    } catch (tetris_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected tetris_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE(
    "operator>>: play game B (reading pieces from stream, rotating, and "
    "inserting them in tetris field)") {
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
    } catch (tetris_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected tetris_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE(
    "operator>>: play game C (reading pieces from stream, rotating, and "
    "inserting them in tetris field)") {
    try {
        std::string path = data_path + "game2.txt";
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
    } catch (tetris_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected tetris_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE(
    "operator>>: play game D (reading pieces from stream, rotating, and "
    "inserting them in tetris field)") {
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
    } catch (tetris_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected tetris_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE(
    "operator>>: play game E (reading pieces from stream, rotating, and "
    "inserting them in tetris field, then GAME OVER)") {
    std::string path = data_path + "game4.txt";

    std::ifstream is(path);
    check_if_found(is);

    uint32_t w = 0;
    uint32_t h = 0;
    is >> w;
    is >> h;
    tetris t(w, h);

    bool thrown = false;
    // int num_piece = 1;
    while (is) {
        piece p;
        is >> p;
        // p.print_ascii_art(std::cout);
        int r = 0;
        is >> r;
        for (int i = 0; i != r; ++i) p.rotate();
        int x = 0;
        is >> x;
        // std::cout << "inserting piece " << num_piece << " at x = " << x
        //           << ":\n";
        // p.print_ascii_art(std::cout);
        // std::cout << '\n';
        // std::cout << '\n';
        try {
            t.insert(p, x);
        } catch (tetris_exception const& /*e*/) {
            // std::cout << e.what() << std::endl;
            thrown = true;
            break;
        }
        // t.print_ascii_art(std::cout);
        // std::cout << '\n';
        // ++num_piece;

        char c = 0;
        is >> c;
        is.putback(c);
    }

    if (!thrown)
        REQUIRE_MESSAGE(false, "ERROR --> exception not thrown when GAME OVER");
}
