cmake_minimum_required(VERSION 3.10)

# set the project name
project(docx)

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)


# ${PROJECT_SOURCE_DIR} is a reserved variable from CMAKE
set(PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
# define where cmake is going to look for source .cpp files
set(PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
# define where cmake is going to put the .exe of the program
set(PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}/build")

# the include directory
include_directories(${PROJECT_SOURCE_DIR}/include/rapidxml)

# define the .cpp files to be compiled
add_executable(main_program src/main.cpp)