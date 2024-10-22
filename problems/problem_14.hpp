#pragma once

#include "../math/math.hpp"

template <std::integral T>
inline T collat(T input) {
    T odd = (input & 1);
    return odd * (3 * input + 1) + (!odd) * (input / 2);
    if(odd)
        return (3 * input + 1);
    else 
        return input / 2;
}

// problem 14
// longest collatz sequence
inline u64 problem_14() {
    constexpr u64 big_num = 1'000'000;
    u64 longest_length = 1; // precalculate 1 as length 1
    u64 longest_i = 1;
    for (u64 i = 2; i < big_num; ++i) {
        u64 length = 0;
        for(u64 tmp_i = i; tmp_i != 1;) {
            length++;
            tmp_i = collat(tmp_i);
        }
        if(longest_length < length){
            longest_length = length;
            longest_i = i;
        }
    }
    std::cout << longest_length << " ";
    return longest_i;
}
