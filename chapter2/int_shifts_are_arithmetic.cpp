#include <iostream>

//判断机器的右移是否为算数右移
int int_shifts_are_arithmetic() {
    return -1 >> 1 == -1;
}

int main(int argc, char const *argv[])
{
    /* code */
    // 输出1,说明是算数右移
    std::cout << int_shifts_are_arithmetic() << std::endl;
    return 0;
}
