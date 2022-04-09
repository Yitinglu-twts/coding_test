#include <stdlib.h>

#if 0
#include <stdio.h>
#include <stdlib.h>

static inline void swap(char *a, char *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

static unsigned int _rev_core(char *head, unsigned int idx)
{
    printf("@[%s] idx = %d\n", __func__, idx);
    if (head[idx] != '\0') {
        printf("#[%s] idx = %d\n", __func__, idx);



        unsigned int end = _rev_core(head, idx + 1);
        printf("##[%s] idx = %d; end: %d\n", __func__, idx, end);
        if (idx > end / 2)
            swap(head + idx, head + end - idx);
        return end;


    }
    return idx - 1;
}

char *str_reverse(char *s)
{
    _rev_core(s, 0);
    return s;
}
#endif

struct test{
    int x;
};

int main(int argc, char *argv[])
{
    char s[] = "abcd";
    //printf("s = %s\n", str_reverse(s));

    struct test t1;
    struct test *p = NULL;//&t1;



    __typeof__(((struct test *)0)->x) n;
    int n;

    printf("p = %p\n",(struct test *)p);


    n = 100;
    printf("n = %d  %d\n", sizeof(n), n);
    //printf("p->x = %d\n",(struct test *)p->x);

    // printf("p = %p\n",((struct test *)0)->x);



    return 0;
}