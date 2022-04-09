#include <stdio.h>
#include <stdlib.h>
/*
*             x->z
*             x->y
*        x->y z->y
*   x->z x->z x->z
*        y->z y->x
*             y->z
*             x->z
*/
int move = 0;
void hanoi(int n, char *tower_x, char *tower_y, char *tower_z)
{
    if (n == 1) {
        printf("move tower:%s to %s\n", tower_x, tower_z);
        move++;
        return;
    }

    hanoi(n-1, tower_x, tower_z, tower_y);
    hanoi(1, tower_x, tower_y, tower_z);
    hanoi(n-1, tower_y, tower_x, tower_z);
}

int main(int argc, char* argv[])
{
    //hanoi(3, "A", "B", "C");
    hanoi(3, "x", "y", "z");
    printf("move: %d\n", move);
    return 0;
}