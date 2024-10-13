#pragma once

#include "../math/math.hpp"
#include <unordered_map>

// Smallest Multiple
// https://projecteuler.net/problem=5
inline int problem_5() {
    // loop through all numbers 2 through 20 and count the max number of dupes for every prime factor
    std::array<int, 20> n_dupes{};

    for (int i = 2; i <= 20; ++i) {
        auto pf = prime_factors(i);
        std::unordered_map<int, int> counts;

        for (auto v : pf)
            ++counts[v];

        for(auto vc : counts) {
            n_dupes[vc.first] = std::max(n_dupes[vc.first], vc.second);
        }
    }

    int total = 1;

    for(int i = 2; i < 20; i++) {
        total *= std::pow(i, n_dupes[i]);
    }

    return total;
}