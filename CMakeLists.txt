cmake_minimum_required(VERSION 3.31)
project(galaxy_generator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(simulation)

add_library(simulationLib
        simulation/Calculator.cpp
        simulation/Calculator.h

        simulation/Galaxy.cpp
        simulation/Galaxy.h

        simulation/Star.cpp
        simulation/Star.h

        simulation/KDTree.cpp
        simulation/KDTree.h

        simulation/Neighbor.cpp
        simulation/Neighbor.h

        simulation/Spacecraft.cpp
        simulation/Spacecraft.h

        simulation/Clock.cpp
        simulation/Clock.h

        simulation/CONSTANTS.h
)

add_executable(galaxy_generator simulation/main.cpp)
target_link_libraries(galaxy_generator PRIVATE simulationLib)


add_executable(Tests simulation/tests.cpp)
target_link_libraries(Tests PRIVATE simulationLib)
