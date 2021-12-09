#include <stdio.h>
#include <string.h>
#include <ctype.h>


void merge_whitespace(char *string);

int main()
{
    char str[] = "Hel lo my        name is";
    
    merge_whitespace(str);
    printf("%s\n", str);
    
    return 0;
}

void merge_whitespace(char *string)
{
    int i = 0, w = 0;
    
    while (string[i] != '\0')
    {
        if(isspace(string[i]))
        {
            //string[w] = 'a';
            //w++;
            i++;
            while(isspace(string[i])){
                i++;
            }
        }
        else{
            string[w] = string[i];
            w++;
            i++;
        }
    }
    string[w] = '\0';
}
