
### CMAKE COMMAND
## cmake -G "MinGW Makefiles" -S .. -B .
## mingw32-make

cmake_minimum_required(VERSION 3.10)

# set the project name
project(docx)

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)


# ${PROJECT_SOURCE_DIR} is a reserved variable from CMAKE
set(PROJECT_ROOT ".")
# define where cmake is going to look for source .cpp files
set(PROJECT_SOURCE_DIR "${PROJECT_ROOT}/src")
# define where cmake is going to put the .exe of the program
set(PROJECT_BINARY_DIR "${PROJECT_ROOT}/build")

# the include directory
include_directories(${PROJECT_ROOT}/include)



# define the .cpp files to be compiled
add_executable(docx src/main.cpp)


# link libxml2 library ------------------------------------------------
# target_link_libraries needs to be after the add_executable command
# because it will use the "docx" name defined by add_executable.
target_link_libraries(docx ${CMAKE_SOURCE_DIR}/lib/libxml2.a)