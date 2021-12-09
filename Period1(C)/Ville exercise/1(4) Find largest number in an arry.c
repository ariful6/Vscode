#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 3

int largest(int *numbers, int count);

int main(void)
{
    int numbers[ARRAY_SIZE];
    int i;
    
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &numbers[i]);
    }
    printf("%d\n", largest(numbers, ARRAY_SIZE));
}

int largest(int *numbers, int count)
{
    int max = 0;
    int i;
    for (i = 0 ; i < count; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    return max;
}
