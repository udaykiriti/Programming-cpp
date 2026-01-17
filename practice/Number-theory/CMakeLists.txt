cmake_minimum_required(VERSION 3.10)
project(NumberTheory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Helper source files
set(HELPER_SOURCES
    include/diophantine.cpp
    include/extgcd.cpp
)

# Add executables for each main file
add_executable(armstrong_number armstrong_number.cpp)
add_executable(count_set_bits count_set_bits.cpp)
add_executable(dec_to_hexa_binary dec_to_hexa_binary.cpp)
add_executable(deci_to_binary deci_to_binary.cpp)
add_executable(euler_totient euler_totient.cpp)
add_executable(extended_euclidean extended_euclidean.cpp ${HELPER_SOURCES})
add_executable(factorial_of_number factorial_of_number.cpp)
add_executable(fast_exponention fast_exponention.cpp)
add_executable(fibonacci_series fibonacci_series.cpp)
add_executable(gcd_lcm gcd_lcm.cpp)
add_executable(linear_diophantine linear_diophantine.cpp ${HELPER_SOURCES})
add_executable(next_palindrome next_palindrome.cpp)
add_executable(palindrome_number palindrome_number.cpp)
add_executable(perfect_number perfect_number.cpp)
add_executable(prime_number prime_number.cpp)
add_executable(reverse_number reverse_number.cpp)
add_executable(sieve sieve.cpp)
add_executable(sqrt sqrt.cpp)
add_executable(strong_number strong_number.cpp)
add_executable(sum_of_all_digits sum_of_all_digits.cpp)
add_executable(chinese_remainder_theorem chinese_remainder_theorem.cpp ${HELPER_SOURCES})
add_executable(prime_factorization prime_factorization.cpp)
add_executable(modular_inverse modular_inverse.cpp ${HELPER_SOURCES})
add_executable(binomial_coefficient binomial_coefficient.cpp)
add_executable(segmented_sieve segmented_sieve.cpp)

# Add Trees Subdirectory
add_subdirectory(trees)
