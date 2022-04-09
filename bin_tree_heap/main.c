#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 100
typedef struct heap_node_t {
    int val;
} heap_node_t;

heap_node_t heap[HEAP_SIZE];


struct heap_head_t {
    int heap_size;
    int heap_usage_num;
    heap_node_t *p_heap;
} heap_head;

void swap(int *v1, int *v2)
{
    int tmp;
    tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

void heap_init(struct heap_head_t *p_header)
{
    p_header->heap_size = HEAP_SIZE;
    p_header->heap_usage_num = 0;
    p_header->p_heap = heap;

}


void heap_insert(struct heap_head_t *p_header, int val)
{
    printf("insert: val = %d\n", val);
    p_header->p_heap[p_header->heap_usage_num].val = val;
    p_header->heap_usage_num++;

    int inserted_num = p_header->heap_usage_num;
    int uppr_level_num = inserted_num >> 1;
    while(uppr_level_num) {
        if (p_header->p_heap[uppr_level_num - 1].val < p_header->p_heap[inserted_num - 1].val) {
            swap(&p_header->p_heap[uppr_level_num - 1].val, &p_header->p_heap[inserted_num - 1].val);
            inserted_num = uppr_level_num;
            uppr_level_num >>= 1;
        } else {
            break;
        }
    }
}
int main(void)
{
    srand(time(NULL));
    heap_init(&heap_head);

    for (int i = 10; i > 0; i--) {
        heap_insert(&heap_head, rand()/1000);
    }

    for (int i = 0; i < heap_head.heap_usage_num; i++) {
        printf("heap[%d] = %d\n", i, heap_head.p_heap[i].val);
    }
    return 0;
}