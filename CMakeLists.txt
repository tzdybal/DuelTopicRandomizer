cmake_minimum_required(VERSION 2.8.11)

add_executable(dtr main.cpp randomizer.h randomizer.cpp cli.h cli.cpp)
set_property(TARGET dtr PROPERTY CXX_STANDARD 11)
