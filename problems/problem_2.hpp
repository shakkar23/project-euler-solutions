#pragma once

#include "../math/math.hpp"

// problem 2
inline u64 problem_2() {
    u64 sum = 0;

    u64 a = 1;
    u64 b = 2;

    while (b < 4'000'000) {
        if (b % 2 == 0) {
            sum += b;
        }

        u64 temp = a;
        a = b;
        b += temp;
    }

    return sum;
}
