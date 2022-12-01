# CMakeList.txt: Tiny_STL 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.0.0)
project(TinySTL VERSION 0.1.0)

include(CTest)
enable_testing()

# 将源代码添加到此项目的可执行文件。
add_executable(TinySTL main.cpp )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
