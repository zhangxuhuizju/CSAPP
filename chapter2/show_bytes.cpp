#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    //%x表示16进制的输出
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

int main(int argc, char const *argv[])
{
    //输出结果为 33 03 00 00,说明int是32位表示，且实验用的机器是小端表示法
    show_int(0x333);
    return 0;
}
