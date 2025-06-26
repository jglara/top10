cmake_minimum_required(VERSION 3.10.0)
project(top10 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -O0")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(01_rain_water)
add_subdirectory(02_mco)
add_subdirectory(03_lcis)
add_subdirectory(04_max_subarray)
add_subdirectory(05_sushi_for_two)
add_subdirectory(06_max_gap)
add_subdirectory(07_max_gap_count)
add_subdirectory(11_strings_cmp)
