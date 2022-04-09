#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y)
{
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void pemu(char *arr, int idx, int total_num)
{
    if (idx == total_num - 1) {
        printf("#: %s\n", arr);
    } else {
        for (int i = idx; i < total_num; i++) {
            swap(&arr[i], &arr[idx]);
            pemu(arr, idx+1, total_num);
            swap(&arr[i], &arr[idx]);
        }
    }
}

#include <stdint.h>
struct {
    uint32_t a;
    uint32_t b;
    uint32_t c;
} x;

int main(void)
{
    char arr[] = "abc";
    // printf("len = %d\n", strlen(arr));
    // pemu(arr, 0, strlen(arr));


    printf("x = %p, x.a = %p, x.b=%p", &x, &x.a, &x.b);

    return 0;
}