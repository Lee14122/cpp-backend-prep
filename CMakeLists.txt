cmake_minimum_required(VERSION 3.10)
project(multi_demo)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
add_executable(app src/main.cpp src/math.cpp src/thread_pool.cpp)