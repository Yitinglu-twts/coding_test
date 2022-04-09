/**
 *          *
 *         / \
 *        +   4
 *       / \
 *      2   3
 *
 *      traverse this bin tree
 */
#include <stdio.h>
#include <stdlib.h>

enum op_type_e {
    OP_NONE = 0,
    OP_PLUS,
    OP_MULTI
};

typedef struct {
    enum op_type_e op;
    int val;

} node_date_t;

typedef struct node_t {
    struct node_t *p_right_node;
    struct node_t *p_left_node;
    node_date_t data;
} node_t;

node_t root;

void bin_tree_build(node_t *p_node, int mode_num)
{
    if (mode_num <= 1)
        return;

    p_node->p_left_node = (node_t*)calloc(1, sizeof(node_t));
    bin_tree_build(p_node->p_left_node, mode_num -=2);
    p_node->p_right_node = (node_t*)calloc(1, sizeof(node_t));
}

void bin_tree_set(node_t *p_node, const node_date_t *p_tree_init_material, int idx, int mode_num)
{


    if (p_node->p_left_node == NULL)
        return;

    bin_tree_set(p_node->p_left_node, p_tree_init_material, idx + 2, mode_num);

    p_node->p_left_node->data = p_tree_init_material[mode_num - idx - 3];
    p_node->p_right_node->data = p_tree_init_material[mode_num - idx - 2];

    if (idx == 0) {
        p_node->data = p_tree_init_material[mode_num-1];
    }
}

void tree_init(node_t *p_root, const node_date_t *p_tree_init_material, int mode_num)
{
    #if 1
    bin_tree_build(p_root, mode_num);
    bin_tree_set(p_root, p_tree_init_material, 0, mode_num);
    #else
    p_root->data.op = OP_MULTI;
    p_root->data.val = 0;
    p_root->p_right_node = (node_t*)calloc(1, sizeof(node_t));
    p_root->p_right_node->data.val = 4;
    p_root->p_right_node->data.op = OP_NONE;

    p_root->p_left_node = (node_t*)calloc(1, sizeof(node_t));
    p_root->p_left_node->data.op = OP_PLUS;
    p_root->p_left_node->p_left_node = (node_t*)calloc(1, sizeof(node_t));
    p_root->p_left_node->p_left_node->data.val = 2;

    p_root->p_left_node->p_right_node = (node_t*)calloc(1, sizeof(node_t));
    p_root->p_left_node->p_right_node->data.val = 3;
    #endif
}

void bin_tree_traverse(node_t *p_node)
{
    if (p_node->p_left_node) {

        bin_tree_traverse(p_node->p_left_node);
        bin_tree_traverse(p_node->p_right_node);
        printf("p_node->data.op = %d, LR val = %d %d \n", p_node->data.op, p_node->p_left_node->data.val, p_node->p_right_node->data.val);
        switch (p_node->data.op) {
            case OP_PLUS:
                p_node->data.val = p_node->p_left_node->data.val + p_node->p_right_node->data.val;
                break;
            case OP_MULTI:
                p_node->data.val = p_node->p_left_node->data.val * p_node->p_right_node->data.val;
                break;
        }
    }
}

int main(void)
{
    node_date_t tree_init_material[] = {
        {.op = OP_NONE, .val = 2},
        {.op = OP_NONE, .val = 3},
        {.op = OP_PLUS},
        {.op = OP_NONE, .val = 4},
        {.op = OP_MULTI},
        {.op = OP_NONE, .val = 6},
        {.op = OP_MULTI},
    };
    tree_init(&root, tree_init_material, sizeof(tree_init_material)/sizeof(tree_init_material[0]));
    printf("before traverse, root val: %d\n", root.data.val);
    bin_tree_traverse(&root);
    printf("after traverse, root val: %d\n", root.data.val);
    return 0;
}