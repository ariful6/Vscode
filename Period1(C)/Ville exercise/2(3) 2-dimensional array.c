#include <stdio.h>
#include <string.h>



int main(void)
{
    int row, col;
    int matrix[5][3] = {};
    int value = 1;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 5; col++) {
            matrix[col][row] = value;
            value++;
        }
    }
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 5; col++) {
            printf("%d\t", matrix[col][row]);
        }
        printf("\n");
    }
    
    return 0;
}
