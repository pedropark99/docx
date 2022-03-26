cmake_minimum_required(VERSION 3.10)

# set the project name
project(docx)

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)

# ${PROJECT_SOURCE_DIR} is a reserved variable from CMAKE
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
# define where cmake is going to look for source .cpp files
SET (PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
# define where cmake is going to put the .exe of the program
SET (PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}/build")

# define the .cpp files to be compiled
add_executable(main_program src/main.cpp)