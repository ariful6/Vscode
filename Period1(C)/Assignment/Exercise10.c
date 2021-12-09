#include <stdio.h>
#include <stdlib.h>
#define NUMBERS "Exercise_10.txt"  // Defining the text file as NUMBERS
#define LINESIZE 100   // Defining LINESIZE as 100

int main()  // Main function
{
    FILE* my_file;  // Pointing FILE to my file
    char line[LINESIZE];
    int count = 0;
    int value = 0;
    int number = 0;
    double sum = 0;
    my_file = fopen(NUMBERS, "r");  // Setting my_file to open the text file
    if (my_file == NULL)
    {
        printf("Unable to open file: %s\n", my_file);  // If there is no file to open print
    }
    else
    {
        fgets(line, LINESIZE, my_file);
        sscanf(line, "%d", &number);  // Scan the numbers
        while (!feof(my_file))
        {
            if (fgets(line, LINESIZE, my_file) != NULL)
            {
                if (sscanf(line, "%d", &value) == 1)
                {
                    sum = sum + value;
                    count++;
                }
            }
        }
        fclose(my_file);  // Close file after scanning
    }


    if (count == number)
    {
        printf("Average of %d numbers is: %.2f\n", count, (double)sum / count);  // Print ave of numbers
    }
    else
    {
        printf("Error! Tried to read %d numbers, %d numbers were read.\n", number, count);  // Print if not enough numbers read
        printf("Average of %d numbers is: %.2f", count, (double)sum / count);  // Print the ave of the numbers read
    }

    return 0;
}
