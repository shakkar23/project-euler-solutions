#pragma once

#include "../math/math.hpp"

template <std::size_t N>
std::vector<u64> get_primes() {
    std::vector<u64> res;  
    auto seive = std::make_unique<std::bitset<N+1>>(0);

    for (u64 i = 2; i < (N+1); ++i) {
        u64 iter = i * i;
        if (iter < (N+1) && !(*seive)[iter]) {
            while (iter < (N+1)) {
                (*seive)[iter] = true;
                iter += i;
            }
        }
    }

    // loop over every prime and add it to the result
    for (u64 i = 2; i < (N+1); ++i) {
        if (!(*seive)[i]) {
            res.emplace_back(i);
        }
    }
    return res;
}

// Squarefree Numbers
inline u64 problem_193() {
    u64 ret = 0;

    auto primes = get_primes<33'554'432>();

    std::cout << primes.size() << " ";

    return 555;

}
