// UNFINISHED
#pragma once

#include "../math/math.hpp"
/*
    Arithmetic Derivative
    Problem 484
*/
inline u64 problem_484() {
    u64 sum = 0; 
    constexpr u64 big = 5 * 10e15;
    const u64 sq_big = std::sqrt(big);

    for (u64 i = 2; i <= big; ++i) {
        int ad = arithmetic_derivative(i);
        sum += ad;

        // print the current i when i mod 1m is 0
        if (i % 1000000 == 0) [[unlikely]] {
            std::cout << "i: " << i << std::endl;
        }

        // print information about the current number
        // std::cout << "\ni: " << std::setw(5) << i << "\tad: " << std::setw(5) << ad << "\tgcd: " << std::setw(5) << std::gcd(ad, i) << '\n';

        // auto pf = prime_factors(i);
        // std::cout << "[";
        // for (const auto &factor : pf) {
        //     std::cout << " " << factor;
        // }
        // std::cout << " ]\n";
    }
    // std::cout << "\nsqrt(big): " << sq_big << std::endl;
    // std::cout << "big = " << big << std::endl;
    return sum;
}

inline void prime_txt_generator() {
    std::vector<u64> primes;
    // loop over 2 to N and find all primes

    constexpr u64 N = 5 * 10e15;
    constexpr u64 upper_bound = 70710678;

    std::unique_ptr<std::bitset<upper_bound>> bits = std::make_unique<std::bitset<upper_bound>>(0);
    //sizeof(std::bitset<upper_bound>);
    for (u64 i = 2; i < upper_bound; ++i) {
        if (!(*bits)[i]) {
            primes.push_back(i);
            for (u64 j = i * i; j < upper_bound; j += i) {
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
