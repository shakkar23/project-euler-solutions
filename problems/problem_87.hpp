#pragma once

#include "../math/math.hpp"

/*
    Prime power triples
    Problem 87
*/
inline int problem_87() {
    std::unique_ptr<std::bitset<50'000'000>> bits = std::make_unique<std::bitset<50'000'000>>(0);

    auto calc = [](int sq, int cu, int te) -> int {
        return sq * sq + cu * cu * cu + te * te * te * te;
    };

    int sq = 2;
    int cu = 2;
    int te = 2;

    while (true) {
        int val = calc(sq, cu, te);
        if (val < 50'000'000) {
            (*bits)[val] = true;
        }

        sq = next_prime(sq);
        if (calc(sq, cu, te) >= 50'000'000) {
            sq = 2;
            cu = next_prime(cu);
            if (calc(sq, cu, te) >= 50'000'000) {
                cu = 2;
                te = next_prime(te);
                if (calc(sq, cu, te) >= 50'000'000) {
                    break;
                }
            }
        }
    }

    return bits->count();
}
