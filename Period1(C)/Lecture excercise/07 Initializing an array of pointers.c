#include <stdio.h>

int main(void)
{
    char *a[] = { "Hello", "World", "How", "are", "you?"};
    int row;
    for(row = 0; row < 5; row++) {
        printf("%s ", a[row]);
    }
    printf("\n");
    
    return 0;
}

