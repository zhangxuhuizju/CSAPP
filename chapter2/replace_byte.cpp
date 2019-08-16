#include <iostream>

//This function replace the i-th byte in the x to b
unsigned replace_byte (unsigned x, int i, unsigned char b) {
    return (x & ~(0xff<<(i<<3))) | (b << (i<<3));
}

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << std::hex <<  replace_byte(0x12345678, 2, 0xAB) << std::endl << replace_byte(0x12345678, 0, 0xAB) << std::endl;
    return 0;
}
