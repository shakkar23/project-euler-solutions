#pragma once

#include "../math/math.hpp"
#include <chrono>

template <std::size_t N>
constexpr std::vector<u64> get_primes() {
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
    constexpr u64 big = 1ull << 50;
    constexpr u64 sqrt_big = 1ull << 25;
    auto big_primes = get_primes<sqrt_big>();
    std::reverse(big_primes.begin(), big_primes.end());
    std::cout << "finished generating primes under sqrt big" << std::endl;
    u64 count = 0;

    for (const u64 &prime_i : big_primes) {  // 2.6mil
        for (u64 large = prime_i * prime_i; large < big; large += prime_i * prime_i) {
            const auto primes = prime_factors_static(large);
            u64 first = primes[0];
            bool colliding = false;

            for (int pi = 1; pi < primes.size(); ++pi) {
                u64 second = primes[pi];

                // check if this number is squareful (opposite of square free)
                // only care about the outcome if the squareful number is larger than the
                colliding |= (first == second) & (first > prime_i);
                first = second;
            }
            count += !colliding;
        }
        std::cout << "finished: " << prime_i << std::endl;
    }
    std::cout << "\n\n";
    return count;
}
