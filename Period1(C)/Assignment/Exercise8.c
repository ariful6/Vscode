#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void capitalize(char *str);

int main(void)
{
    char str1 [200];
    char str2[] = "STOP";
    char str3[] = "stop";
    
        // strncmp() comparing string until 4 values
    int  x = strncmp(str1, str2, 4);
    int  y = strncmp(str1, str3, 4);
    
    while ((x != 0) && (y != 0)) {

        printf("Enter a String: ");
        fgets(str1, sizeof(str1), stdin);   //reads string
        x = strncmp(str1, str2, 4);
        y = strncmp(str1, str3, 4);
        capitalize(str1);
        printf("Converted String: %s\n",str1);
        }
    return 0;
}

void capitalize(char *str)
{
    int i = 0;

    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]) && str[i-1] == ' ') {
            str[i] = toupper(str[i]);
        }
        else if (isalpha(str[0])) {
            str[0] = toupper(str[0]);
        }
    }

}
