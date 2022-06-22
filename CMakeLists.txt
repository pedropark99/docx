
### CMAKE COMMAND
## cmake -G "MinGW Makefiles" -S .. -B .
## mingw32-make

cmake_minimum_required(VERSION 3.10)

# set the project name
project(docx)

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)


# define where cmake is going to look for source .cpp files
set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
# define where cmake is going to put the .exe of the program
set(PROJECT_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")

# the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# This -D option is necessary to avoid
# undefined reference to `__imp_xmlNewDoc' error
set(CMAKE_CXX_FLAGS "-DIN_LIBXML")



# define the .cpp files to be compiled
add_executable(docx src/main.cpp src/paragraphs.cpp)


# link libxml2 library ------------------------------------------------

# link_directories() will add directoies for linker to look for libraries
# link_directories("/usr/lib")
# link_directories("/usr/lib/x86_64-linux-gnu")

# target_link_libraries needs to be after the add_executable command
# because it will use the "docx" name defined by add_executable.
# link_directories(AFTER "lib")

target_link_libraries(docx "lzma")
target_link_libraries(docx "iconv")
target_link_libraries(docx "z")
#target_link_libraries(docx "ws2_32")
target_link_libraries(docx "xml2")