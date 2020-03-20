cmake_minimum_required(VERSION 3.15)
project(DiningPhilosophers)

set(CMAKE_CXX_STANDARD 20)

add_executable(DiningPhilosophers main.cpp Philosopher.cpp Philosopher.h)

target_link_libraries(DiningPhilosophers pthread)
target_link_libraries(DiningPhilosophers ncurses)