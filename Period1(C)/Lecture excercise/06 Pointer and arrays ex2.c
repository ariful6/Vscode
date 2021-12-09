#include <stdio.h>

#define ARRAY_SIZE 5

int sum (int *values, int length);

int main(void)
{
    int grades[ARRAY_SIZE];
    
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("Enter a number: ");
        scanf("%d", &grades[i]);
    }
    printf("Sum of the grade is: %d\n", sum(grades, ARRAY_SIZE));
}

int sum (int *values, int length)
{
    int result = 0;
    int i = 0;
    
    for(i = 0; i < length; i++)
    {
        result += values[i];
    }
    return result;
}
