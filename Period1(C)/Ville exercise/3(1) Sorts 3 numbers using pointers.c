#include <stdio.h>

void sort3(int *a, int *b, int *c);

int main()
{
    int n1 = 5, n2 = 3, n3 = 9;
    
    sort3(&n1, &n2, &n3);
    printf("%d, %d, %d\n", n1, n2, n3);
    
}

void sort3(int *a, int *b, int *c)
{
    int temp;
    
    if (*a > *b && *a > *c)
    {
        temp = *a;
        *a = *c;
        *c = temp;
    }
        if (*a > *b && *a < *c)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
        if (*c < *a && *c < *b)
    {
        temp = *c;
        *c = *a;
        *a = temp;
    }
        if (*c > *a && *c < *b)
    {
        temp = *c;
        *c = *b;
        *b = temp;
    }
}
