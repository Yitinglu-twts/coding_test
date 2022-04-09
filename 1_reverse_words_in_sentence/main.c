#include <stdio.h>
#include <stdlib.h>


void swap_c(char *x, char *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int str_reverse_core(char *str, int idx)
{
    if (str[idx] != '\0') {
        int end = str_reverse_core(str, idx+1);
        if (idx > (end >> 1)) {
            swap_c(&str[idx], &str[end - idx]);
        }
        return end;
    }
    return idx-1;
}

void str_reverse(char *str)
{
    str_reverse_core(str, 0);
}

void str_reverse2(char *str)
{
    int len = 0, idx = 0;
    for (len = 0; str[len]!='\0'; len++) {
        if (str[len] == ' ') {
            str[len] = '\0';
            //printf("sub(idx %d): %s\n", idx, &str[idx]);
            str_reverse_core(&str[idx], 0);
            idx = len + 1;
        }
    }
    str_reverse_core(&str[idx], 0);

    len -= 1;
    for (;len > 0; len--) {
        if (str[len] == '\0') {
            str[len] = ' ';
        }
    }
}

int main(int argc, char* argv[])
{
    char str[] = "this is a test string";
    str_reverse2(str);
    printf("%s\n", str);
    return 0;
}