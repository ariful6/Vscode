#include <stdio.h>
#include <stdlib.h>

int stringLength(const char string[]);
void concat(char result[], const char str1[], const char str2[]);

int main()
{
    const char word1[] = "Jason";
    const char word2[] = "ok";
    const char word3[] = "whatever";
    char result[50];
    
    printf(" %d   %d    %d\n", stringLength(word1), stringLength(word2), stringLength(word3));
    
    concat(result, word1, word2);
    
    printf(" %s\n", result);
    
    return 0;
}

int stringLength(const char string[])
{
    int count = 0;
    
    while(string[count] != '\0')
        ++count;
    
    return count;
}

void concat(char result[], const char str1[], const char str2[])
{
    int i, j;
    
    for(i = 0; str1[i] != '\0'; ++i)
    {
        result[i] = str1[i];
    }
    
    for(j = 0; str2[j] != '\0'; ++j)
    {
        result[i + j] = str2[j];
    }
    result[i + j] = '\0';

}
