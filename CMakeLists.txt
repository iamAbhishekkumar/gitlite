cmake_minimum_required(VERSION 3.30)
project(gitlite)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB SOURCES ${SRC_DIR}/*.cpp)

add_executable(gitlite ${SOURCES})

# target_link_libraries()
# Link libraries for testing (for example, if using GoogleTest)
# find_package(GTest REQUIRED)
# target_link_libraries(demo_test GTest::GTest GTest::Main)

