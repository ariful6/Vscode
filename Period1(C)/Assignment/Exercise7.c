#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void spaceToUnderscore (char *string);

int main(void)
{
    char str1 [200];
    char str2[] = "STOP";
    char str3[] = "stop";
    
        // strncmp() comparing string until 4 values
    
    while ((strncmp(str1, str2, 4) != 0) && (strncmp(str1, str3, 4) != 0)) {
        printf("Enter a String: ");
        fgets(str1, sizeof(str1), stdin);   //reads string
        spaceToUnderscore(str1);
        printf("Converted String: %s\n",str1);
    }

    return 0;
}

void spaceToUnderscore (char *string)
{
    int i = 0;
    for (i = 0; string[i]; i++) {
        //replaces white space with underscore
        if (string[i] == ' ') {
            string[i] = '_';
        }
    }

}
