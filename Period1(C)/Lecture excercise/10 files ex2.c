#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 80

int main()
{
    FILE *my_file;
    char line[LINESIZE];
    int lc = 0;
    
    my_file = fopen("hello.txt", "r");
    
    if (my_file == NULL) {
        printf("Unable to open the file\n");
    }
    else{
        printf("The following was read from the file\n");
        while (!feof(my_file)) {
            if (fgets(line, LINESIZE, my_file) != NULL) {
                lc++;
                printf("%2d: %s", lc, line);
            }
        }
        fclose(my_file);
    }
    
    return 0;
}

