#include <stdio.h>
#include <string.h>
#define LINESIZE 100

struct item_record  // Structure for price information
{
    char product[100];
    double price;

};
struct item_record items[21]; // Number of items the structure holds

int fileName() // The file itself
{
    char filename[LINESIZE];
    char line[LINESIZE];
    FILE* file;
    double x = 0;
    char a[100] = {};
    int count = 0;

    printf("Please enter the name of the file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) // If there is no file to begin with
    {
        printf("The file does not exist.\n");
        return 0;
    }

    while (!feof(file))  // Reading the file
    {
        if (fgets(line, LINESIZE, file) != NULL)
        {
            count++;
            if (count < 21)
            {
                if (sscanf(line, "%lf;%[^\n]s", &x, a) != 0)
                {
                    items[count - 1].price = x;
                    strcpy(items[count - 1].product, a);
                }
            }
        }
    }
    fclose(file);

    if (count > 0);
    return count; // Returns the number of items on the list
}

int main()
{
    int count = fileName();

    if (count == 0)
    {
        printf("The file does not exist.");
    }

    else if (count > 0 && count < 21) // If the number of items on the list is < 21
    {
        printf("%d items were read\n", count);
        printf("%-50s%-50s\n", "Name", "Price");
        for (int i = 0; i < count; i++)
        {
            printf("%-50s%-50.2lf\n", items[i].product, items[i].price); // Prints the items in formatted columns
        }
    }
    else
    {
        printf("Excess items were on this file, only the first 20 items were read.\n");  // If the number of items on the list is > 21
        printf("%-50s%-50s\n", "Name", "Price");
        for (int i = 0; i < 20; i++)
        {
            printf("%-50s%-50.2lf\n", items[i].product, items[i].price); // Only the first 20 are read and printed in formatted columns
        }
    }
    return 0;
}
