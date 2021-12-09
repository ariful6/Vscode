#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STR_SIZE 30

bool remove3rd(char *str);

int main()
{
    char text[STR_SIZE] = "abcdefg";
    char text2[STR_SIZE];
    
    remove(text);
    text2[100] = text[100];

    printf("%d\n", remove(text));
    
}

bool remove3rd(char *str)
{
    
    if (strlen(str) < 3 ){
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++){
        str[i] = str[i+1];
    }
    return true;
}
