#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 32

int main(void)
{
    char giberrish[STR_SIZE];
    int i = 0;
    int count = rand() % STR_SIZE;
    
    for (i = 0; i < count; i++) {
        giberrish[i] = rand() % 26 + 'A';
    }
    giberrish[i] = '\0';
    
    printf("Random stuff: %s\n", giberrish);
}
