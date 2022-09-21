# Require a minimum version of cmake.
# https://cmake.org/cmake/help/v3.16/command/cmake_minimum_required.html?highlight=cmake_minimum_required
cmake_minimum_required(VERSION 3.16)

# Set the name of the project.
# https://cmake.org/cmake/help/v3.16/command/project.html?highlight=project
project(demo
    VERSION 0.0.0.1
    DESCRIPTION "This is a demo project about C plus plus."
    HOMEPAGE_URL "https://github.com/wengerbinning"
    LANGUAGES CXX
)


# Add an executable to the project using the specified source files.
# https://cmake.org/cmake/help/v3.16/command/add_executable.html?highlight=add_executable
add_executable(helloworld helloworld.cpp)


