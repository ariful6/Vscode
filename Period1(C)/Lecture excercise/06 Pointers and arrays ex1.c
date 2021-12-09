#include <stdio.h>

void swap1(int x, int y);
void swap2(int *x, int *y);

int main(void)
{
    int m = 0, n = 1;
    
    printf("Starting vales : m, n = %d, %d\n", m, n);
    swap1(m, n);                                        //calls by value
    printf("After swap1(): m, n = %d, %d\n", m, n);
    swap2(&m, &n);                                      // calls by reference
    printf("After swap2(): m, n = %d, %d\n", m, n);
    
    return 0;
}

//swap1 : sawps copies of values
void swap1(int x, int y)
{
    int temp;
    
    temp = x;
    x = y;
    y = temp;
}

// swap2: swaps values of the address given
void swap2(int *x, int *y)
{
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}
