cmake_minimum_required(VERSION 2.6)
project (Prac4)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link all files in Task 4 directory
file(GLOB task4_src
     "*.h"
     "*.cpp"
)

add_executable(main ${task4_src})
target_link_libraries(main ${GTEST_LIBRARIES} pthread)