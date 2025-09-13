cmake_minimum_required(VERSION 3.16)
project(rpn_calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(rpn src/rpn.cpp)
target_include_directories(rpn PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(rpn_calculator src/main.cpp)
target_link_libraries(rpn_calculator PRIVATE rpn)
