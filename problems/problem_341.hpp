#pragma once
#include "../math/math.hpp"
inline auto p341_g(std::vector<std::pair<u64, u64>>& D, u64 n) {
    int64_t N = n;
    for (int64_t i = 0; i < D.size(); i++) {
        N -= D[i].second;

        if (N == 0)
            return D[i].first;
        else if (N < 0)
            return D[i - 1].first;
    }
}

inline auto p341_gen_d_n(std::vector<std::pair<u64, u64>>& D, u64 n) {
    auto p = std::make_pair(n, D[n - 1 - 1].second + p341_g(D, n));

    return p;
}

inline u64 problem_341() {
    std::vector<std::pair<u64, u64>> D = {{1, 1}, {2, 2}};
    // (n, D_n-1_y+g(n-1))

    for (u64 i = 3; i <= 6137; i++) {
        D.push_back(p341_gen_d_n(D, i));
    }
    constexpr u64 s = 1000000000000000000;
    u64 sum = 0;
    for (u64 i = 1; i < 1'000'000; i++) {
        sum += p341_g(D, i * i * i);
    }

    return sum;
}