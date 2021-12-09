#include <stdio.h>

int main(void)
{
    //int a[5][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    int a[5][3] = { {1, 2}, {3, 4, 5}, {6} , {7, 8} , {9, 10} };
    int row;
    int col;

    for(row = 0; row < 5; row ++){
        for(col = 0; col < 3; col ++){
            printf("%d ", a[row][col]);
        }
        printf("\n");
    }
    return 0;
}
