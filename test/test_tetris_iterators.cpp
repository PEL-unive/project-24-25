#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("Iterators") {
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

        pel_2425::tetris const t1_const{t1};
        tetris const t2_const{t2};

        {
            auto next = t2.begin();
            bool equal_incr = (++(next++)) == (++t2.begin());
            equal_incr &= (++t2.begin() == next);

            REQUIRE_MESSAGE(equal_incr == true,
                            "ERROR --> one of iterator:: ++, ++(int), == is "
                            "not correctly implemented");
        }

        auto it1 = t1.begin();  // our implementation
        bool equal_arrow = true, equal_deref = true;
        for (auto it2 = t2.begin(); it2 != t2.end() and it1 != t1.end();
             ++it2) {
            equal_arrow &= equal_pieces(it1->p, it2->p);
            equal_arrow &= (it1->x == it2->x and it1->y == it2->y);

            equal_deref &= equal_pieces((*it1).p, (*it2).p);
            equal_deref &= ((*it1).x == (*it2).x and (*it1).y == (*it2).y);

            ++it1;
        }

        REQUIRE_MESSAGE(equal_arrow == true,
                        "ERROR --> one of iterator:: ->, ++, != is not "
                        "correctly implemented");
        REQUIRE_MESSAGE(equal_deref == true,
                        "ERROR --> one of iterator:: *, ++, != is not "
                        "correctly implemented");

        {
            auto next = t2_const.begin();
            bool equal_incr = (++(next++)) == (++t2_const.begin());
            equal_incr &= (++t2_const.begin() == next);

            REQUIRE_MESSAGE(equal_incr == true,
                            "ERROR --> one of const_iterator:: ++, ++(int), == "
                            "is not correctly implemented");
        }

        auto it1_const = t1_const.begin();
        equal_arrow = true;
        equal_deref = true;
        for (auto it2_const = t2_const.begin();
             it2_const != t2_const.end() and it1_const != t1_const.end();
             ++it2_const) {
            equal_arrow &= equal_pieces(it1_const->p, it2_const->p);
            equal_arrow &=
                (it1_const->x == it2_const->x and it1_const->y == it2_const->y);

            equal_deref &= equal_pieces((*it1_const).p, (*it2_const).p);
            equal_deref &= ((*it1_const).x == (*it2_const).x and
                            (*it1_const).y == (*it2_const).y);

            ++it1_const;
        }

        REQUIRE_MESSAGE(equal_arrow == true,
                        "ERROR --> one of const_iterator:: ->, ++, != is not "
                        "correctly implemented");
        REQUIRE_MESSAGE(equal_deref == true,
                        "ERROR --> one of const_iterator:: *, ++, != is not "
                        "correctly implemented");

    } catch (tetris_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected tetris_exception thrown: "
                                   << e.what());
    }
}