#pragma once

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <numeric>
#include <set>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

using u64 = uint64_t;
using s64 = int64_t;

inline std::vector<u64> prime_factors(u64 n) {
    std::vector<u64> factors;
    factors.reserve(std::log2(n));

    u64 i = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            factors.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

// skull emoji
inline int next_prime(int cur_num) {
    if (cur_num == 2) {
        return 3;
    }

    if (cur_num == 3) {
        return 5;
    }

    int next_num = cur_num + 2;
    bool is_prime = false;

    while (!is_prime) {
        is_prime = true;
        int next_num_sqrt = std::sqrt(next_num);
        for (int i = 2; i <= next_num_sqrt; i++) {
            if (next_num % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (!is_prime) {
            next_num += 2;
        }
    }

    return next_num;
}

// https://en.wikipedia.org/wiki/Arithmetic_derivative
inline auto arithmetic_derivative(u64 n) -> u64 {
    u64 ret = 0;
    std::vector<u64> factors = prime_factors(n);

    u64 factor_sum = n;

    for (const u64 &factor : factors) {
        ret += factor_sum / factor;
    }
    return ret;
};

// https://en.wikipedia.org/wiki/M%C3%B6bius_function
inline int mobius(int n) {
    std::vector<u64> factors = prime_factors(n);
    std::set<u64> unique_factors(factors.begin(), factors.end());

    if (unique_factors.size() != factors.size()) {
        return 0;
    }

    return (factors.size() % 2 == 0) ? 1 : -1;
}
