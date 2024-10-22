#include <map>

#include "math/math.hpp"
#include "problems/all_problems.hpp"

int main(const int argc, const char *const argv[]) {
    // std::cout << "Problem 1: " << problem_1() << std::endl;
    // std::cout << "Problem 2: " << problem_2() << std::endl;
    // std::cout << "Problem 3: " << problem_3() << std::endl;
    // std::cout << "Problem 5: " << problem_5() << std::endl;
    // std::cout << "Problem 10: " << problem_10() << std::endl;
    // std::cout << "Problem 14: " << problem_14() << std::endl;
    // std::cout << "Problem 24: " << problem_24() << std::endl;
    // std::cout << "Problem 87: " << prime_power_triples() << std::endl;
    // std::cout << "Problem 102: " << problem_102() << std::endl;
    std::cout << "Problem 193: " << problem_193() << std::endl;
    // std::cout << "Problem 484: " << problem_484() << std::endl;
    // prime_txt_generator();
    // std::cout << "Problem 698: " << problem_698() << std::endl;
    // std::cout << "Problem 903" << problem_903() << std::endl;
    return 0;
    for(const auto &lem : lehmer_code(std::vector<u64>{9,8,7,6,5,4,3,2,1,0})){
        std::cout << lem << " ";
    }
    std::cout << std::endl;

    return 0;
}
