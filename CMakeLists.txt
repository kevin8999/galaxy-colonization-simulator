cmake_minimum_required(VERSION 3.31)
project(galaxy_generator)

set(CMAKE_CXX_STANDARD 14)

include_directories(simulation)

add_executable(galaxy_generator
        simulation/Calculator.cpp
        simulation/Calculator.h
        simulation/Galaxy.cpp
        simulation/Galaxy.h
        simulation/Star.cpp
        simulation/Star.h
        simulation/main.cpp
)
