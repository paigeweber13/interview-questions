cmake_minimum_required(VERSION 3.17)
project(my_program)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_program main.cpp lib.cpp lib.hpp)

find_package(Catch2)
IF (Catch2_FOUND)
    message(STATUS "Catch2 found, generating test executable")
    add_executable(my_program_tests tests.cpp lib.cpp lib.hpp)
    target_link_libraries(my_program_tests Catch2::Catch2)
ELSE ()
    message(STATUS "Catch2 not found, not generating test executable")
ENDIF ()
