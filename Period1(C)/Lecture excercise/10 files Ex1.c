#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *my_file;
    
    my_file = fopen("hello.txt", "r");
    
    if (my_file == NULL) {
        /*File is not opened*/
        printf("File did not open (file do not exist)\n");
    }
    else{
        /*File was successfully opened*/
        printf("File opened successfully\n");
    }
    
    return 0;
}
