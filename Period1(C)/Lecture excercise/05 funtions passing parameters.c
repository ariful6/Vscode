#include <stdio.h>

int sum(int x, int y);

int main(void)
{
    int a;
    int x;
    int number;
    
    printf("Enter number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &x);
    
    number = sum(a , x);
    
    printf("Result = %d\n", number);
   
    return 0;
}

int sum(int x, int y)
{
    int result = 0;
    
    result = x + y;
    return result;
}
