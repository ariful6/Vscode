#include <stdio.h>
#include <string.h>

void sequence(int num1, int num2);
int main()
{
    sequence(8, 9);
}
void sequence(int num1, int num2)
{
    while (num1<=num2)
    {
        {
        printf("%d\n", num1);
        num1++;
        }
    }
    printf("\n");
}
