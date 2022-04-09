#include <stdio.h>
#include <string.h>
#include <stdint.h>

void *__stack_chk_guard = (void *)0xdeadbeef;

void __stack_chk_fail(void)
{
    fprintf(stderr, "##Stack smashing detected##\n");
    exit(1);
}

void test(void)
{
    char str[10];
    strcpy(str, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}

int main(void)
{
    test();
    return 0;
}