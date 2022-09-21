cmake_minimum_required(VERSION 3.1)
project(loadwav)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
#SET(CMAKE_BUILD_TYPE Debug)

add_subdirectory(wave)


# 指定生成目标
add_executable(Demo main.cpp)

# 添加链接库
target_link_libraries(Demo wave)
