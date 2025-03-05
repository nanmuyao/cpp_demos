cmake_minimum_required(VERSION 3.10)  # 指定所需的最低 CMake 版本

project(MyProject LANGUAGES CXX)  # 定义项目名称和使用的编程语言

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # 设置可执行文件的输出目录

# 查找 ZLIB 库，确保其可用
find_package(ZLIB REQUIRED)

# 添加可执行文件，并指定其源文件
add_executable(MyProject src/main.cpp)

# 链接 ZLIB 库到可执行文件
target_link_libraries(MyProject ZLIB::ZLIB)