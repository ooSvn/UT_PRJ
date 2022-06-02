cmake_minimum_required(VERSION 3.1.0)  # CMake version check
project(ap)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++14 standard

set(SRC_DIRECTORY sources)
set(INCLUDE_DIRECTORY headers)

# Add main.cpp file of project root directory as source file
set(SOURCES
    ${SRC_DIRECTORY}/bishop.cpp
    ${SRC_DIRECTORY}/board.cpp
    ${SRC_DIRECTORY}/king.cpp
    ${SRC_DIRECTORY}/knight.cpp
    ${SRC_DIRECTORY}/null.cpp
    ${SRC_DIRECTORY}/pawn.cpp
    ${SRC_DIRECTORY}/queen.cpp
    ${SRC_DIRECTORY}/rook.cpp
)

# Add executable target with source files listed in SOURCE_FILES variable
include_directories(${INCLUDE_DIRECTORY})
add_executable(${PROJECT_NAME}
    ${SRC_DIRECTORY}/main.cpp
    ${SOURCES})