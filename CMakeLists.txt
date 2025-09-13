cmake_minimum_required(VERSION 3.16)
project(rpn_calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(rpn src/rpn.cpp)
target_include_directories(rpn PUBLIC ${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(rpn_tests tests/test_rpn.cpp)
target_link_libraries(rpn_tests PRIVATE rpn GTest::gtest_main)
target_include_directories(rpn_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(rpn_tests)
