#include <iostream>
#include "lower_one_mask.cpp"
/**
 * do rotating left shift, assume 0 <= n < w
 * for example, when x = 0x12345678 and w = 32
 * n = 4 -> 0x23456781, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n) {
    return (x << n) | (x >> (32-n));
}

int main(int argc, char const *argv[])
{
    std::cout << std::hex << rotate_left(0x12345678, 4) << " " << rotate_left(0x12345678, 20) << std::endl;
    return 0;
}
