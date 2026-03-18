#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("piece::operator>>, rotate, insert, containment") {
    std::string path(data_path + "game1.txt");
    std::ifstream is(path);
    std::ifstream correct_is(path);
    check_if_found(is);
    check_if_found(correct_is);
    uint32_t w = 0;
    uint32_t h = 0;
    is >> w;
    is >> h;
    tetris t(w, h);
    correct_is >> w;
    correct_is >> h;
    pel_2425::tetris correct_t(w, h);
    int num_piece = 0;

    /* read half game and build two tetris */
    while (num_piece != 5) {
        piece p;
        is >> p;
        int r = 0;
        is >> r;
        for (int i = 0; i != r; ++i) p.rotate();
        pel_2425::skip(is);
        int x = 0;
        is >> x;
        t.insert(p, x);
        pel_2425::skip(is);

        pel_2425::piece correct_p;
        correct_is >> correct_p;
        r = 0;
        correct_is >> r;
        for (int i = 0; i != r; ++i) correct_p.rotate();
        pel_2425::skip(correct_is);
        x = 0;
        correct_is >> x;
        correct_t.insert(correct_p, x);
        pel_2425::skip(correct_is);

        ++num_piece;
    }

    bool equal = equal_tetris(t, correct_t);
    REQUIRE_MESSAGE(equal == true,
                    "ERROR --> tetris game not built correctly (some "
                    "rotate/insert/piece::operator>> operation failed)");
    equal = equal_tetris_non_const(t, correct_t);
    REQUIRE_MESSAGE(equal == true,
                    "ERROR --> tetris game not built correctly (some "
                    "rotate/insert/piece::operator>> operation failed)");

    std::uniform_int_distribution<uint64_t> distr(0, h);
    std::default_random_engine gen(time(NULL));  // randomize

    /* then use the rest of the pieces for (random) containment queries */
    while (true) {
        piece p;
        is >> p;
        int r = 0;
        is >> r;
        for (int i = 0; i != r; ++i) p.rotate();
        pel_2425::skip(is);
        int x = 0;
        is >> x;
        pel_2425::skip(is);

        pel_2425::piece correct_p;
        correct_is >> correct_p;
        r = 0;
        correct_is >> r;
        for (int i = 0; i != r; ++i) correct_p.rotate();
        pel_2425::skip(correct_is);
        int correct_x = 0;
        correct_is >> correct_x;
        pel_2425::skip(correct_is);

        for (int i = 0; i != 5; ++i) {
            int y = distr(gen);
            REQUIRE_MESSAGE(t.containment(p, x, y) ==
                                correct_t.containment(correct_p, correct_x, y),
                            "ERROR --> some containment operations failed");
        }

        char c = is.peek();
        if (c < '0' or c > '9') break;
    }
}
