#include <iostream>
/**
 * mask with least significant n bits set to 1
 * examples: n=6 -> 0x3f, n=17 -> 0x1ffff
 * attention to the case that n = w
 */
int lower_one_mask(int n) {
    //溢出也无所谓，0-1结果补码表示就是全1
    return (2 << (n-1)) - 1;
}

// int main(int argc, char const *argv[])
// {
//     std::cout << std::hex << lower_one_mask(6) << "  " << lower_one_mask(32) << "  " << lower_one_mask(17) << std::endl;
//     return 0;
// }
