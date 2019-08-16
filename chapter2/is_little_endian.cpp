#include <iostream>

int is_little_endian() {
    int a = 1;
    return *((char*)(&a));
}

int main(int argc, char const *argv[])
{
    //实验机器输出1,表示是小端机器
    std::cout << is_little_endian() << std::endl;
    return 0;
}