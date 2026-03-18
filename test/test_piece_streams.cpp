#include <iostream>
#include <sstream>

#include "util.hpp"
#include "our_implementation/src/tetris.cpp"
#include "tetris.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

using namespace pel_2425::test;

TEST_CASE("piece::operator>>") {
    std::string path(data_path + "pieces.txt");
    std::ifstream in1(path);
    std::ifstream in2(path);
    check_if_found(in1);
    check_if_found(in2);
    while (in1 and in2) {
        piece p;
        pel_2425::piece correct_p;
        in1 >> p;
        in2 >> correct_p;
        // p.print_ascii_art(std::cout);
        // correct_p.print_ascii_art(std::cout);
        bool equal = equal_pieces(p, correct_p);
        REQUIRE_MESSAGE(equal == true, "ERROR --> pieces loaded incorrectly");
    }
}

TEST_CASE("piece::operator<<") {
    const uint64_t num_cells = 50;

    for (int i = 0; i != 5; ++i) {
        uint32_t log2_side = get_random_uint(1, 10, i + 89);
        uint32_t side = 1ULL << log2_side;
        uint8_t color = get_random_uint(1, 255, i + 4);
        std::uniform_int_distribution<uint64_t> distr(0, side - 1);
        std::default_random_engine gen(i + 13);  // randomize

        std::vector<std::pair<uint32_t, uint32_t>> filled_cells;
        filled_cells.reserve(num_cells);
        for (uint64_t i = 0; i != num_cells; ++i) {
            filled_cells.push_back({distr(gen), distr(gen)});
        }
        piece p = create_test_piece<piece>(side, color, filled_cells);
        pel_2425::piece correct_p =
            create_test_piece<pel_2425::piece>(side, color, filled_cells);

        std::ostringstream oss_p;
        std::ostringstream oss_correct_p;
        oss_p << p;
        oss_correct_p << correct_p;
        std::string result_p = oss_p.str();
        std::string result_correct_p = oss_correct_p.str();
        std::istringstream iss_p(result_p);
        std::istringstream iss_correct_p(result_correct_p);
        piece another_p;
        pel_2425::piece another_correct_p;
        iss_p >> another_p;
        iss_correct_p >> another_correct_p;
        bool equal = equal_pieces(another_p, another_correct_p);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR on operator>> --> piece loaded and/or saved "
                        "from/to stream incorrectly");
    }
}