cmake_minimum_required(VERSION 3.28)
project(galaxy_generator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(simulation
        simulation/src/Calculator.cpp
        simulation/include/Calculator.h

        simulation/src/Galaxy.cpp
        simulation/include/Galaxy.h

        simulation/src/Star.cpp
        simulation/include/Star.h

        simulation/src/KDTree.cpp
        simulation/include/KDTree.h

        simulation/src/Neighbor.cpp
        simulation/include/Neighbor.h

        simulation/src/Spacecraft.cpp
        simulation/include/Spacecraft.h

        simulation/src/Clock.cpp
        simulation/include/Clock.h

        simulation/include/CONSTANTS.h

)

target_include_directories(simulation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/simulation/include)

add_executable(galaxy_generator simulation/src/main.cpp)
target_link_libraries(galaxy_generator PUBLIC simulation)

# Tests
add_executable(Tests simulation/src/tests.cpp)
target_link_libraries(Tests PUBLIC simulation)
