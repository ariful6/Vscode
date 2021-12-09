#include <stdio.h>

int main(void)
{
    int apple = 3;
    int *fruit;
    fruit = &apple;
    printf("Apple = %d\n", *fruit);
}
