#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count(char *str);

int main()
{
    char str[] = "Hello My Name Is Arif";
    char str1[] = "he is bad boy";
    printf("%d\n", count(str));
    printf("%d\n", count(str1));
}

int count(char *str)
{
    int j = 0;
    int i = 0;

        for (i = 0; i< strlen (str); i++)
        {
            if (str[i]>= 'A' && str[i]<= 'Z')
            j++;
        }

    return j;
}
