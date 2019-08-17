unsigned srl(unsigned x, int k) {
    unsigned xsra = (int)x >> k;
    //用算数右移实现逻辑右移，需要将前面最高的k位清0
    int w = sizeof(int)*8;
    unsigned z = 2 << (w-k-1);
    return (z-1) & xsra;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int w = sizeof(int)*8;
    unsigned z = 1 << (w-k-1);
    int mask = z - 1;
    //右移之后的w-k-1位
    unsigned int right = xsrl & mask;
    unsigned int left = (~(z & xsrl)) + 1;
    return left | right;
}