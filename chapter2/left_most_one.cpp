#include <iostream>
/**
 * Generate mask indicating leftmost 1 in x, assume w = 32;
 * for example 0xff00 -> 0x8000, 0x6600 -> 0x 4000
 * if x = 0, return 0
 */
int left_most_one(unsigned x) {
    //hint, transfer x -> [0...011...1]
    //then the result will be x ^ (x >> 1)
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}

int main(int argc, char const *argv[])
{
    std::cout << std::hex << left_most_one(0xff00) << "   " << left_most_one(0x6600) << std::endl;
    return 0;
}
