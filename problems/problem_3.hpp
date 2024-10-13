
#pragma once

#include "../math/math.hpp"

// problem 3

inline u64 problem_3() {
    u64 n = 600851475143;
    std::vector<u64> factors = prime_factors(n);
    return factors.back();
}