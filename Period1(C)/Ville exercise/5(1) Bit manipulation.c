#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool read_line(char *line, size_t size);
bool binary_reader(unsigned int *pu);
int digit_counter(unsigned int nr);

int main(int arcg, char **argv)
{
    unsigned int number = 0;

    while(binary_reader(&number)) {
        printf("%11u: %08X, %d\n", number, number, digit_counter(number));
    };

    return 0;

}

bool read_line(char *line, size_t size)
{
    
    return true;
}

bool binary_reader(unsigned int *pu)
{
    
    return true;
}

int digit_counter(unsigned int nr)
{
    return 1;
}
