#include <iostream>
#include "float_le.cpp"
typedef unsigned float_bits;

/**
 * compute -f if f is NAN, return f
 */
float_bits float_negative(float_bits f) {
    unsigned signal = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    int is_NAN = (exp == 0xff) && (frac != 0);
    if (is_NAN)
        return f;
    else return ~signal << 31 | exp << 23 | frac; 
}

/**
 * compute |f|. if f is NAN, then return f.
 */
float_bits float_absval(float_bits f) {
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if (exp == 0xff && frac != 0)
        return f;
    else return exp << 23 | frac | 0 << 31;
}

/**
 * compute 2*f. if f is NaN, then return f.
 */
float_bits float_twice(float_bits f) {
    unsigned signal = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    //浮点数的指数为255,×2后无法表示，直接返回f
    if (exp == 0xff)
        return f;
    //如果浮点鼠的指数是0,则为非规格化浮点数。如果此时frac的第23位不为1,则将frac左移一位即可
    //若frac的第23位为1,那么左移之后exp + 1
    //若exp是254,那么直接置为无穷即可
    //其他情况exp + 1即可
    if (exp == 0) {
        frac <<= 1;
        int over = frac & 0x800000;
        if (over) {
            exp = 1;
            frac ^= 0x800000;
        }
    } else if (exp == 0xfe) {
        exp = 0xff;
        frac = 0;
    } else {
        exp += 1;
    }
    return signal << 31 | exp << 23 | frac;
}
 
int main(int argc, char const *argv[])
{
    std::cout << u2f(float_twice(f2u(23.22))) << std::endl;
    return 0;
}
