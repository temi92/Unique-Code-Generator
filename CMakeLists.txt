cmake_minimum_required(VERSION 3.5)
set (PROJECT_NAME UCG)

set(CMAKE_CXX_STANDARD 11)

project(${PROJECT_NAME})
#Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp src/BitSumGenerator.cpp )
include_directories(include)
add_library(lib src/CheckSumGenerator.cpp src/PngParser.cpp)
# Add an executable with the above sources
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} lib -lpng )
add_subdirectory(tests)