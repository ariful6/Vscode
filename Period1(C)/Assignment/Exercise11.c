#include <stdio.h>
#include <stdlib.h>
#define SORT "Exercise_11.txt"  // Defininging SORT as the file Exercise_11.txt
#define LINESIZE 100  // defining the linesize as 100 characters

void sort(int* p, int size)  // Declaration and initialisation of sort function
{
    int i, j;
    for (i = 0; i < size - 1; ++i)
    {
        for (j = 0; j < size - i - 1; ++j)
        {
            if (p[j] > p[j + 1])
            {
                int temp;
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main()  // Main function
{

    FILE* my_file; // Pointer to my_file
    int a[LINESIZE];
    int i;


    my_file = fopen(SORT, "r");  // Open myfile, parameter Exercise_11.txt

    if (my_file == NULL)
    {
        printf("%s does not exist\n", SORT);  // Prints if Exercise_11.txt is empty
        return 0;
    }
    for (i = 0; i < 3;i++)
    {
        fscanf_s(my_file, "%d", &a[i]);
    }

    sort(a, 3);  // Calls sort function

    my_file = fopen(SORT, "w");

    for (i = 0; i < 3;i++)
    {
        fprintf(my_file,"%d", a[i]);
    }
    fclose(my_file);

    return 0;
}
