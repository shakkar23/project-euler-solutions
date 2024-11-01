#pragma once

#include "../math/math.hpp"



inline u64 problem_188() {
    constexpr u64 num = 1777;

    u64 rep = 100'000'0000;
    std::vector<u64> exp_mods{rep};

    // find the rpttns to limit the number of times that i have to loop in the final loop 
    // as in this example the final mod == 1 which nullifies all higher powers
    u64 iter = 0;
    u64 base = num;
    u64 orig_base = base;
    while (rep > 1) {
        while (true) {
            iter++;
            base *= num;
            base %= rep;
            if (base == orig_base) {
                std::cout << iter << std::endl;
                exp_mods.emplace_back(iter);
                rep = iter;
                base = num % rep;
                orig_base = num % rep;
                iter = 0;
                break;
            }
        }
    }

    u64 ret = 0;
    std::reverse(exp_mods.begin(), exp_mods.end());
    for (const auto &mod : exp_mods) {
        ret = pow_mod(num, ret, mod);
    }

    return ret;  // 95962097
}
