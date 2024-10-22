#pragma once
#include "../math/math.hpp"

// current impl doesnt work, need to make sure that every number of numbers in the number also is a valid 1-2-3 number
inline auto problem_698() {
    constexpr u64 input = 111'111'111'111'222'333;
    constexpr u64 mod = 123123123;

    auto func = [](u64 n) -> std::string {
        // create the input into a string of base 3

        std::string base_3 = "";

        if (n == 0) {
            base_3 = "0";
        }

        while (n > 0) {
            base_3 = std::to_string(n % 3) + base_3;
            n /= 3;
        }

        base_3.back() = base_3.back() + 1;

        return base_3;
    };

    auto base_3 = func(input % mod - 1);

    for (int i = 0; i < 10; ++i) {
        std::cout << i + 1 << ": " << func(i) << std::endl;
    }

    return base_3;
}
