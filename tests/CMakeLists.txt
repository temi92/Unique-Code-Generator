cmake_minimum_required(VERSION 3.5)

# Set the project name
project (${PROJECT_NAME})

add_subdirectory(google-test)

# enable CTest testing
enable_testing()
# Add a testing executable
add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests lib
    GTest::GTest 
    GTest::Main -lpng
)
add_test(test_all unit_tests)
