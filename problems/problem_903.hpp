#pragma once
#include "../math/math.hpp"

template <std::size_t N, std::integral T>
std::vector<T> k_to_perm(T k) {
    k = k % factorial(N);
    // given a k, return the permutation at the kth lexicographic index
    std::vector<T> perm;
    std::vector<T> nums;
    for (T i = 0; i < N; ++i) {
        nums.emplace_back(i);
    }

    for (T i = 0; i < N; ++i) {
        T fact = factorial(N - 1 - i);
        T index = k / fact;
        k = k % fact;
        perm.emplace_back(nums[index]);
        nums.erase(nums.begin() + index);
    }

    return perm;
}

// Total Permutation Powers
u64 problem_903() {
    std::cout << "\n";

    for (u64 i = 0; i < factorial(4); ++i) {
        std::vector<u64> perm = k_to_perm<4>(i);
        for (const auto &p : perm) {
            std::cout << p << " ";
        }
        std::cout << std::endl;
    }
    return 101010;
    u64 sum = 0;

    constexpr u64 N = 4;

    std::map<u64, u64> map;
    // get the permutations of 123, and store them in a vector of array<int,3>
    std::vector<std::array<uint16_t, N>> permutations;
    // iota the array
    std::array<uint16_t, N> arr{};
    std::iota(arr.begin(), arr.end(), 1);

    do {
        permutations.push_back(arr);
    } while (std::next_permutation(arr.begin(), arr.end()));

    // for every permutation, map the ith element to the array[i]th element
    for (const auto &permutation : permutations) {
        for (int i = 0; i < N; ++i) {
            std::cout << permutation[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < N; ++i) {
            map[i + 1] = permutation[i];
        }

        auto goes_to = [=](int i) mutable {
            return map[i];
        };

        // print the map
        // for (const auto &i : permutation) {
        //     int to = i;
        //     constexpr int fac = factorial(N);
        //     for (int j = 1; j < fac; ++j) {
        //         to = goes_to(to);
        //     }
        //     std::cout << to << " ";
        // }
        // std::cout << std::endl;
        // std::cout << std::endl;
        // std::cout << std::endl;
    }
    return 0;
}