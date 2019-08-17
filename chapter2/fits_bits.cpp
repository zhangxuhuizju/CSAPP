/**
 * returns 1 when x can be represented as an n-bit, 2's-complement number
 * 0 otherwise
 * assume 1<=n<=w
 */
int fit_bits(int x, int n) {
    //判断是否在 -2^(n-1) ~ 2^(n-1)-1范围内
    //若在，则n-1位为符号位，前面所有位都是符号位
    x >>= (n-1);
    return !x || !(~x);
}