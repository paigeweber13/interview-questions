cmake_minimum_required(VERSION 3.17)
project(longest_substring)

set(CMAKE_CXX_STANDARD 14)

add_executable(longest_substring main.cpp longestSubstring.cpp)

find_package(Catch2 REQUIRED)
IF (Catch2_FOUND)
    message(STATUS "Catch2 found, generating test executable")
    add_executable(longest_substring_test tests.cpp longestSubstring.cpp)
    target_link_libraries(longest_substring Catch2::Catch2)
ELSE ()
    message(STATUS "Catch2 not found, not generating test executable")
ENDIF ()
