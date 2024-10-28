#pragma once

#include "../math/math.hpp"

inline u64 problem_9() {
    constexpr u64 max = 1000;

    for (int a = 1; a <= max - 2; ++a) {
        for (int b = max - a - 1; b >= 0; --b) {
            int c = max - a - b;
            if(c*c == a*a + b*b) {
                // std::cout << "found a solution: " << a << " " << b << " " << c << std::endl;
                if(a*b*c != 0)
                    return a*b*c;
            }
            //std::cout << a << " " << b << " " << c << std::endl;
        }
    }
    return 0;
}