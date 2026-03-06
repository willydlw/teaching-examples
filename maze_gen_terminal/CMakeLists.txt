cmake_minimum_required(VERSION 3.28.3)

# Project name 
project(mazegen)

# set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # enforce the standard strictly 
set(CMAKE_CXX_EXTENSIONS OFF) # do not allow compiler extensions 


# set output directory 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# include directories 
include_directories(${CMAKE_SOURCE_DIR}/include)


file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

# set target-specific compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -g -Wall -Wextra -pedantic)