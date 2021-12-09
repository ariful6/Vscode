#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 80

int main(void)
{
    char text[STR_SIZE] = "Pointers are important part";
    const char *t2 = " of C programming language\n";
    
    printf("Length = %d\n", strlen(text));
    
    strcat(text, t2);
    
    printf("Length = %d\n", strlen(text));
    printf("String: %s\n", text);
    
    return 0;
}
