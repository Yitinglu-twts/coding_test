#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int _ffs(uint8_t i)
{
    uint8_t v = 1;

    if (i == 0) {
        return 0;
    }

    if (!(i & 0xf)) {
        v += 4;
        i >>= 4;
    }
    if (!(i & 0x3)) {
        v += 2;
        i >>= 2;
    }
    if (!(i & 0x1)) {
        v += 1;
        i >>= 1;
    }
    return v;
}

int main(void)
{
    for (uint8_t i = 0; i < 10; i++) {
        printf("i = %d(0x%02x) , ffs = %d\n", i, i, ffs(i));
    }
    for (uint8_t i = 0; i < 10; i++) {
        printf("i = %d(0x%02x) , _ffs = %d\n", i, i, _ffs(i));
    }
    return 0;
}
