#pragma once
#include "../math/math.hpp"


/*
    Problem 24: Lexicographic permutations
*/
std::string problem_24() {
    std::vector<int> set = {0,1,2,3,4,5,6,7,8,9};
    std::sort(set.begin(), set.end());
    constexpr int N = 1'000'000;

    for (int i = 1; i < N; ++i) {
        std::next_permutation(set.begin(), set.end());
    }

    std::string result = "[ ";

    // [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]

    for (const int &i : set) {
        result += std::to_string(i) + " ";
    }
    result += "]";

    return result;
}