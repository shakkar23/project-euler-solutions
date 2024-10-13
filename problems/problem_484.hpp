// UNFINISHED
#pragma once

#include "../math/math.hpp"
/*
    Arithmetic Derivative
    Problem 484
*/
inline u64 problem_484() {
    u64 sum = 0;

    auto f = [](u64 n) -> s64 {
        s64 ret = 0;

        s64 sqrt_n = std::sqrt(n);
        for (int i = 1; i < sqrt_n; ++i) {
            ret += mobius(i) * n / i;
        }

        return ret;
    };

    //\sum_{\prod p^k} gcd(\prod p^k, (\prod p^k)') [f(\prod p^k) - \prod (k-1)]
}

void prime_txt_generator() {
    std::vector<u64> primes;
    // loop over 2 to N and find all primes

    constexpr u64 N = 5 * 1'000'000'000'000'000;
    constexpr u64 sqrt_N = 70710678;

    std::unique_ptr<std::bitset<sqrt_N>> bits = std::make_unique<std::bitset<sqrt_N>>(0);

    for (u64 i = 2; i < sqrt_N; ++i) {
        if (!(*bits)[i]) {
            primes.push_back(i);
            for (u64 j = i * i; j < sqrt_N; j += i) {
                (*bits)[j] = true;
            }
        }
    }

    std::cout << "primes.size(): " << primes.size() << std::endl;

    // push all the primes into a file with a newline between each prime
    std::ofstream file("primes.txt");
    for (const u64 &prime : primes) {
        file << prime << std::endl;
    }
    file.close();
}
