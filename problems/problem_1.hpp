#pragma once

#include "../math/math.hpp"

/*
    Multiples of 3 and 5
    Problem 1
*/

u64 problem_1() {
    u64 sum = 0;

    for (u64 i = 0; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}