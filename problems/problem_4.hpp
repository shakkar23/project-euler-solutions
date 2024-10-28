#pragma once
#include "../math/math.hpp"

// problem 4
inline u64 problem_4() {
    u64 max = 0;
    for (u64 i = 100; i < 1000; ++i) {
        for (u64 j = 100; j < 1000; ++j) {
            u64 product = i * j;
            if (is_palindrome(product) && product > max) {
                max = product;
            }
        }
    }
    return max;
}