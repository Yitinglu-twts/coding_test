#include <stdint.h>
#include <stdio.h>

uint8_t bit8_reverse(uint8_t d)
{
    d = ((d & 0xaa) >> 1) | ((d & 0x55) << 1);
    d = ((d & 0xcc) >> 2) | ((d & 0x33) << 2);
    d = ((d & 0xf0) >> 4) | ((d & 0x0f) << 4);
}


int main(int argc, char* argv[])
{
    uint8_t data = 0x36;
    printf("reverse 0x%02x\n", bit8_reverse(data));
}