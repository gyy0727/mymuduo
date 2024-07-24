#!/bin/bash
###
 # @Author: Gyy0727 3155833132@qq.com
 # @Date: 2024-03-24 16:47:47
 # @LastEditors: Gyy0727 3155833132@qq.com
 # @LastEditTime: 2024-04-02 12:57:46
 # @FilePath: /muduo/automake.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 

# 删除 lib、build 和 bin 目录下的所有文件
echo "Deleting files in lib directory..."
rm -rf lib/*

echo "Deleting files in build directory..."
rm -rf build/*

echo "Deleting files in bin directory..."
rm -rf bin/*

# 执行 cmake
echo "Running cmake..."
cmake -S . -B build

# 切换到 build 目录
cd build

# 执行 make 构建项目
echo "Building project..."
make

echo "Build completed."
echo "------------------------------------------------------------------"
cd ..

cd ./bin

# 获取当前目录下所有可执行文件的列表
./muduo 

# 遍历可执行文件列表，并执行每个文件


# 退出 bin 目录
cd ..