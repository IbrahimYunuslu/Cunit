cmake_minimum_required(VERSION 3.5)

project(pw1 LANGUAGES C)

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra -g" )

include_directories("include")

add_executable(testing "")
target_sources(testing PUBLIC src/test.c src/header.c)

target_link_libraries( testing PUBLIC m cunit )

enable_testing()

add_test( Test1 testing )