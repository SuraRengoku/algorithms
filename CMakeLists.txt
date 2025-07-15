cmake_minimum_required(VERSION 3.10)
project(Algorithm)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)
# Include headers
# include_directories(include)
include_directories(src/hot100)
include_directories(src/LCR)

# Collect all source files
# file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
# list(FILTER SOURCES EXCLUDE REGEX "src/hot100/.*")

# Add source files
# add_executable(Algorithm main.cpp ${SOURCES})
add_executable(Algorithm main.cpp)

