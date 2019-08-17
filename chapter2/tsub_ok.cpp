#include <iostream>

/**
 * determine whether arguments can be subtracted without overflow
 * return 1 if ok; 0 otherwise
 */
int tsub_ok(int x, int y) {
    int res = x - y;
    x >>= 31;
    y >>= 31;
    res >>= 31;
    int pos_ovf = ~x & y & res;
    int neg_ovf = x & ~y & ~res;
    int novf = ~(pos_ovf | neg_ovf);
    return novf & 1;
}

int main(int argc, char const *argv[])
{
    std::cout << tsub_ok(2147483111, -1245) << " " << tsub_ok(8544, 44) << " " << tsub_ok(2147483640, -8) << std::endl;
    return 0;
}
