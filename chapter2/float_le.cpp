unsigned f2u(float x) {
    return *(unsigned *)(&x);
    //利用c语言的指针转化即可！！！
}

float u2f(unsigned x) {
    return *(float *)(&x);
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return sx == sy ? (sx == 0 ? ux <= uy : ux >= uy) : sx > sy; 
}
