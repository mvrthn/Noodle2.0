cmake_minimum_required(VERSION 3.25)

project(Noodle)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FILES "./src/*.cpp" "./src/*.hpp" "./src/Ingredients/*.hpp"  "./src/Flavors/*.cpp" "./src/Flavors/*.hpp")

add_executable(Noodle ${SRC_FILES})
