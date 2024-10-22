#pragma once

#include "../math/math.hpp"

/*
    Summation of primes
    Problem 10
*/

u64 problem_10() {
    constexpr int big = 2'000'000;
    auto seive = std::make_unique<std::bitset<big + 1>>(0);

    int redundant = 0;
    for (u64 i = 2; i < big; ++i) {
        u64 iter = i * i;
        if (iter < big && !(*seive)[iter]) {
            while (iter < big) {
                (*seive)[iter] = true;
                iter += i;
            }
        }
    }

    u64 sum = 0;

    for (int i = 2; i < big; ++i) {
        if (!(*seive)[i]) {
            sum += i;
        }
    }
    return sum;
}
