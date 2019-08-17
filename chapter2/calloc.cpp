#include <string.h>
#include <stdlib.h>

void *calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0)
        return NULL;
    size_t allocate_size = nmemb * size;
    if (allocate_size / nmemb != size)
        return NULL;
    void *p = malloc(allocate_size);
    if(!p)
        return NULL;
    memset(p, 0, allocate_size);
    return p;
}