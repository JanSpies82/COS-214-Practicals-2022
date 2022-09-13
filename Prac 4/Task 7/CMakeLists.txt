cmake_minimum_required(VERSION 2.6)
project (Prac4)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link all files in Task 5 directory
file(GLOB task7_src
     "*.h"
     "*.cpp"
)

add_executable(main ${task7_src})
target_link_libraries(main ${GTEST_LIBRARIES} pthread)