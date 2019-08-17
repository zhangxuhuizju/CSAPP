#include <iostream>
#define TMax 2147483647
#define TMin -2147483648
/**
 * addition that saturates to Tmin or Tmax
 */
int saturating_add(int x, int y) {
    int res = x + y;
    x >>= 31;
    y >>= 31;
    res >>= 31;
    int pos_ovf = ~x & ~y & res;
    int neg_ovf = x & y & ~res;
    int no_ovf = ~(pos_ovf | neg_ovf);
    return (pos_ovf & TMax) | (no_ovf & res) | (neg_ovf & TMin);
}

int main(int argc, char const *argv[])
{
    std::cout << saturating_add(2147480000, 5555) << " " << saturating_add(2541, 58841266) << " " << saturating_add(-2147483333, -126454) << std::endl;
    return 0;
}
