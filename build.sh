conan install . --output-folder=build --build=missing  # 使用 Conan 安装依赖并输出到 build 目录

cd build  # 进入 build 目录
cmake ..  # 运行 CMake 配置项目，进入项目的上一级目录， 查找CMakeLists.txt，生成构建系统文件
# make  # 使用 Make 构建项目

cmake --build . --config Debug  # 使用 CMake 构建项目，指定 Release 配置

# cd ../bin/Release  # 进入生成的可执行文件所在的目录
# ./MyProject  # 运行生成的可执行文件 MyProject