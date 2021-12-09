#include <stdio.h>

int main(void)
{
    char string [256];
    
    printf("Insert your full address: ");
    gets (string);
    printf("Your address is: %s \n",string);

    return 0;
}
