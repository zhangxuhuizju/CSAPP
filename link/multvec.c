int multcnt = 0;

void multivec(int *x, int *y, int *z, int n) {
    int i;
    
    multcnt++;

    for (i = 0; i < n; ++i)
        z[i] = x[i] * y[i];
}