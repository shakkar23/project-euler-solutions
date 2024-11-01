
cmake_minimum_required(VERSION 3.22)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 23)

# find all the files in the problems directory
file(GLOB_RECURSE problems_headers "problems/*.hpp")

# create a header file for the main file that includes all the files in the problems directory
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.hpp)
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.hpp "#pragma once\n")
foreach(header ${problems_headers})
    file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.hpp "#include \"${header}\"\n")
endforeach()
file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.hpp "void all_problems();\n")

#generate a cpp file that calls every problem, each problem function being labeled at "problem_#()"
file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.cpp)
file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.cpp "#include \"all_problems.hpp\"\n")
file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.cpp "#include <iostream>\n\n")

file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.cpp "void all_problems() {\n")
foreach(header ${problems_headers})
    # use the basename of the header file to get the problem number
    get_filename_component(stripped_header ${header} NAME_WE)
    file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.cpp "\tstd::cout << \"${stripped_header}: \" << ${stripped_header}() << std::endl;\n")
endforeach()
file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/generated/all_problems.cpp "}\n")



set(problem_number 188)

# add the executable
add_executable(HelloWorld "main.cpp" "generated/all_problems.cpp")
# add the PROBLEM macro that should expand to "problem_#"
target_compile_definitions(HelloWorld PRIVATE PROBLEM=problem_${problem_number})
# add the INCLUDE macro that should expand to the path to the include directory
# it looks like "problems/problem_#.hpp"
target_compile_definitions(HelloWorld PRIVATE INCLUDE="problems/problem_${problem_number}.hpp")


# add -march=native to the compiler flags
if(LINUX)
    # assume that we use a compiler that supports the -march=native flag when on linux
    target_compile_options(HelloWorld PRIVATE -march=native)
endif()
