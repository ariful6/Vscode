#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INDEX 15
#define MAXLENGTH 30
#define FILENAME "Exercise_13.txt"

void readstring(char *line, int *len, int *stop);
void writestring(char *line, int len);

int main()
{
    char *line;

    size_t x = 0;
    int length = 16;
    int len = 0;
    int stop = 1;
    int index = 0, i = 0;

    line = (char *)malloc(length + 1);

    while (stop != 0 && strcmp(line, ".\n"))
    {
        printf("User enter a string: "); // Asking user to input a sting
        fgets(line, length, stdin);

        if (line[strlen(line) - 1] != '\n')
        {
            printf("1\n");
            index = length;
            int ch;
            while ((ch = fgetc(stdin)) != '\n' && ch != EOF)
            {
                printf("2\n");
                length++;
                line = (char *)realloc(line, length + 1);
                line[index - 1] = ch;
                index++;
            }
            line[length - 1] = '\0';
        }
        printf("3\n");
        readstring(line, &len, &stop);
        writestring(line, len);
        *line = 0;
    }
    return 0;
}

void readstring(char *retline, int *len, int *stop) // Read string function
{
    printf("4\n");

    int i = 0;
    while (i < strlen(retline) && stop[0] == 1)
    {
        if (retline[i] == '.') // When function 'reads' '.'
        {
            stop[0] = 0;
            retline[i + 1] = '\0'; // It 'reads' it as the 'null' character for end of string
        }
        if (retline[i] == '\n')
        {
            retline[i] = '\0';
        }
        i++;
    }
    len[0] = i;
}

void writestring(char *line, int len) // Write string to file function
{
    printf("5\n");
    FILE *read_file = fopen("Exercise_13.txt", "w");
    if (!read_file)
    {
        printf("\n Unable to open : %s ", read_file);
    }
    else
    {
        fprintf(read_file, "%d:%s\n", len - 1, line);
    }
    fclose(read_file);
}
