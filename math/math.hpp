#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <concepts>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>
#include <numeric>
#include <ranges>
#include <set>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

using u64 = uint64_t;
using s64 = int64_t;

template <typename Range>
concept RandAccessRange = std::ranges::random_access_range<Range>;

template <typename Iter>
concept BidirectionalIterator = std::bidirectional_iterator<Iter>;

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

inline std::array<u64, 64> prime_factors_static(u64 n) {
    std::array<u64, 64> factors;
    factors.fill(1);

    u64 i = 2;
    u64 j = 0;

    while (i * i <= n) {
        if (n % i == 0) {
            factors[j] = i;
            n /= i;
            j++;
        } else {
            i++;
        }
    }

    if (n > 1) {
        factors[j] = n;
    }

    return factors;
}

// i made this function up, its terrible
template <std::integral T>
constexpr inline T next_prime(T cur_num) {
    if (cur_num == 2) {
        return 3;
    }

    if (cur_num == 3) {
        return 5;
    }

    T next_num = cur_num + 2;
    bool is_prime = false;

    while (!is_prime) {
        is_prime = true;
        T next_num_sqrt = std::sqrt(next_num);
        for (T i = 2; i <= next_num_sqrt; i++) {
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
inline u64 mobius(u64 n) {
    std::vector<u64> factors = prime_factors(n);
    std::set<u64> unique_factors(factors.begin(), factors.end());

    if (unique_factors.size() != factors.size()) {
        return 0;
    }

    return (factors.size() % 2 == 0) ? 1 : -1;
}

// self explanatory
template <std::integral T>
constexpr inline T factorial(T n) {
    T result = 1;
    for (T i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to compute the lexicographic index of a permutation
template <std::forward_iterator It, std::sentinel_for<It> S>
    requires(std::totally_ordered<std::iter_reference_t<It>>)
constexpr inline u64 lexicographic_index(It first, S last) {
    u64 result = 0;
    auto n = std::ranges::distance(first, last);  // Get the size of the range

    for (const auto it : std::views::iota(first, last)) {
        // Count how many elements after *j are smaller than *j
        auto k = std::count_if(std::ranges::next(it), last, [&](const auto& val) {
            return val < *it;
        });

        // Add k * factorial of remaining elements
        result += k * factorial(n - std::ranges::distance(first, it) - 1);  
    }

    return result;
}

template <std::ranges::forward_range Rng>
    requires(std::totally_ordered<std::ranges::range_reference_t<Rng>>)
constexpr inline auto lexicographic_index(Rng&& rng) {
    return lexicographic_index(std::ranges::begin(rng), std::ranges::end(rng));
}

// Function to calculate the Lehmer code for a range of elements
template <std::forward_iterator It, std::sentinel_for<It> S>
    requires(std::totally_ordered<std::iter_reference_t<It>>)
constexpr inline auto lehmer_code(It first, S last) {
    std::vector<std::iter_difference_t<It>> lehmer;

    for (const auto it : std::views::iota(first, last)) {
        const auto count = std::ranges::count_if(
            std::ranges::next(it), last,

            [&](const auto& val) {
                return val < *it;
            });

        lehmer.push_back(count);
    }

    return lehmer;
}

template <std::ranges::forward_range Rng>
    requires(std::totally_ordered<std::ranges::range_reference_t<Rng>>)
constexpr inline auto lehmer_code(Rng&& rng) {
    return lehmer_code(std::ranges::begin(rng), std::ranges::end(rng));
}

inline bool is_palindrome(u64 n) {
    std::string str = std::to_string(n);
    return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}

inline u64 pow_mod(u64 base, u64 exp, u64 mod) {
    u64 ret = 1;

    while (exp > 0) {
        if (exp % 2 == 1)
            ret = (ret * base) % mod;
        // square when possible which should limit the number of operations by a lot
        base = (base * base) % mod;
        exp = exp / 2;
    }

    return ret;
}
