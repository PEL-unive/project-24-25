#pragma once

#include <random>
#include <ctime>
#include <exception>

namespace pel_2425::test {

const std::string data_path("../test_data/");

void check_if_found(std::istream& is) {
    if (!is.good()) throw std::runtime_error("file not found");
}

/*
    Note: we assume here that insert() never throws, i.e.,
    we do not have a GAME OVER.
*/
template <typename Piece, typename Tetris>
void play(std::istream& is, Tetris& t) {
    uint32_t w = 0;
    uint32_t h = 0;
    is >> w;
    is >> h;
    t = Tetris(w, h);

    // int num_piece = 1;
    while (is) {
        Piece p;
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
        t.insert(p, x);
        // t.print_ascii_art(std::cout);
        // std::cout << '\n';
        // ++num_piece;

        char c = 0;
        is >> c;
        is.putback(c);
    }
}

template <typename Piece>
Piece create_test_piece(
    uint32_t side, uint8_t color,
    std::vector<std::pair<uint32_t, uint32_t>> const& filled_cells) {
    Piece p(side, color);
    for (auto cell : filled_cells) p(cell.first, cell.second) = true;
    return p;
}

uint64_t get_random_uint(const uint64_t lowerbound, const uint64_t upperbound,
                         uint64_t seed = time(NULL)  // randomize
) {
    std::uniform_int_distribution<uint64_t> distr(lowerbound, upperbound);
    std::default_random_engine gen(seed);
    return distr(gen);
}

template <typename Piece1, typename Piece2>
bool equal_pieces(Piece1 const& p1, Piece2 const& p2) {
    if (p1.side() == p2.side() and p1.color() == p2.color()) {
        for (uint32_t i = 0; i != p1.side(); ++i) {
            for (uint32_t j = 0; j != p1.side(); ++j) {
                if (p1(i, j) != p2(i, j)) return false;
            }
        }
        return true;
    }
    return false;
}

template <typename Tetris1, typename Tetris2>
bool equal_tetris(Tetris1 const& t1, Tetris2 const& t2) {
    if (t1.score() == t2.score() and  //
        t1.width() == t2.width() and  //
        t1.height() == t2.height())   //
    {
        auto begin_t1 = t1.begin();
        auto end_t1 = t1.end();
        auto begin_t2 = t2.begin();
        auto end_t2 = t2.end();
        while (begin_t1 != end_t1 and begin_t2 != end_t2) {
            if (begin_t1->x != begin_t2->x or  //
                begin_t1->y != begin_t2->y or  //
                !equal_pieces(begin_t1->p, begin_t2->p)) {
                return false;
            }
            ++begin_t1;
            ++begin_t2;
        }
        if (begin_t1 != end_t1 or begin_t2 != end_t2) return false;
        return true;
    }
    return false;
}

template <typename Tetris1, typename Tetris2>
bool equal_tetris_non_const(Tetris1& t1, Tetris2& t2) {
    if (t1.score() == t2.score() and  //
        t1.width() == t2.width() and  //
        t1.height() == t2.height())   //
    {
        auto begin_t1 = t1.begin();
        auto end_t1 = t1.end();
        auto begin_t2 = t2.begin();
        auto end_t2 = t2.end();
        while (begin_t1 != end_t1 and begin_t2 != end_t2) {
            if (begin_t1->x != begin_t2->x or  //
                begin_t1->y != begin_t2->y or  //
                !equal_pieces(begin_t1->p, begin_t2->p)) {
                return false;
            }
            ++begin_t1;
            ++begin_t2;
        }
        if (begin_t1 != end_t1 or begin_t2 != end_t2) return false;
        return true;
    }
    return false;
}

}  // namespace pel_2425::test