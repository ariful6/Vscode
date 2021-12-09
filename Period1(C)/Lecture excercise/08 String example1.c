#include <stdio.h>
#include <string.h>

int main (void)
{
    char str[20] = "Hello, World";
    int length ;

    for(length = 0; str[length] != '\0'; length++)
    
        printf("length = %d\n", length);

}
