#pragma once
#include "../math/math.hpp"

// Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0
inline u64 problem_206() {
    const u64 lower_bound = std::sqrt(1020304050607080900);
    const u64 upper_bound = std::sqrt(1929394959697989990);
    auto check = [](u64 input) {
        bool ret = ((input / 1                          ) % 10 == 0) 
                && ((input / 1'00                        ) % 10 == 9) 
                && ((input / 1'00'00                     ) % 10 == 8) 
                && ((input / 1'00'00'00                  ) % 10 == 7) 
                && ((input / 1'00'00'00'00               ) % 10 == 6) 
                && ((input / 1'00'00'00'00'00            ) % 10 == 5) 
                && ((input / 1'00'00'00'00'00'00         ) % 10 == 4) 
                && ((input / 1'00'00'00'00'00'00'00      ) % 10 == 3) 
                && ((input / 1'00'00'00'00'00'00'00'00   ) % 10 == 2) 
                && ((input / 1'00'00'00'00'00'00'00'00'00) % 10 == 1)
                ;

        return ret;
        // lmao
        if ((input / 1) % 10 == 0) {
            if ((input / 1'00) % 10 == 9) {
                if ((input / 1'00'00) % 10 == 8) {
                    if ((input / 1'00'00'00) % 10 == 7) {
                        if ((input / 1'00'00'00'00) % 10 == 6) {
                            if ((input / 1'00'00'00'00'00) % 10 == 5) {
                                if ((input / 1'00'00'00'00'00'00) % 10 == 4) {
                                    if ((input / 1'00'00'00'00'00'00'00) % 10 == 3) {
                                        if ((input / 1'00'00'00'00'00'00'00'00) % 10 == 2) {
                                            if ((input / 1'00'00'00'00'00'00'00'00'00) % 10 == 1) {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    };

    u64 result{};
    // we can +=10 because we know that the last digit is 0, so we must be on a multiple of 10
    for (u64 i = lower_bound; i < upper_bound; i+=10) {
        if (check(i * i)) {
            result = i;
            break;
        }
    }
    return result;
}
