#include <stdint.h>
#include <stdio.h>

uint32_t num_of_set_bit(uint32_t n)
{
    uint32_t num = 0;
    while(n) {
        num += n & 1;
        n >>= 1;
    }
    return num;
}

int main(int argc, char* argv[])
{
    uint32_t n = 0xc3;
    printf("0x%x: num of set bit = %d\n", n, num_of_set_bit(n));

    int x[] = {3, 5};
    int *p_x = x;

    printf("x = %d\n", (*p_x)++);
    printf("x = %d %d\n", x[0], x[1]);
    return 0;
}