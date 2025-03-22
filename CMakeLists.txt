cmake_minimum_required(VERSION 3.10)  # 指定所需的最低 CMake 版本


project(MyProject LANGUAGES CXX)  # 定义项目名称和使用的编程语言

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# 开启debug模式
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # 设置可执行文件的输出目录

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

# 查找 ZLIB 库，确保其可用
find_package(ZLIB REQUIRED)

# 查找 mongoose 库，确保其可用
find_package(mongoose REQUIRED)

# 添加可执行文件，并指定其源文件
add_executable(MyProject src/main.cpp)

# 链接 ZLIB 库到可执行文件
target_link_libraries(MyProject ZLIB::ZLIB)

# 链接 mongoose 库到可执行文件
target_link_libraries(MyProject mongoose::mongoose)
