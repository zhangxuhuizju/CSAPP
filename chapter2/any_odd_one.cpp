#include <iostream>
/**
 * return 1 when any odd bit of x equals, otherwise return 0
 * assume w = 32;
 */

int any_odd_one(unsigned x) {
    return !(!x & 0x55555555);
}

//return 1 when x contains odd number of 1s; 0 otherwise;
int odd_ones(unsigned x) {
    //对x的每一位进行 ^ 操作，最后所得的结果即为需要的返回值
    //利用二分法进行，提高效率
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

int main(int argc, char const *argv[])
{
    std::cout << odd_ones(0b110101) << std::endl;
    return 0;
}
