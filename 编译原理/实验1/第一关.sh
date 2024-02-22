#!/bin/bash
gcc -D BILIBILI def-test.c -c alibaba.c
gcc -o def-test def-test.o alibaba.o
# 请用 gcc 编译器，连编def-test.c, alibaba.c，生成def-test二进制可执行代码。通过在编译命令行加适当的参数，
# 使生成的程序能形成Alibaba和Bili两个人的对话：
