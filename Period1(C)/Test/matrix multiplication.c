#include <stdio.h>

void multiplying(int vector[3], int matrix[3][3], int result[3])
{
    int rows, colm, calci = 0;
    for (rows = 0; rows < 3; rows++)
    {
        for (colm = 0; colm < 3; colm++)
        {
            calci += vector[colm] * matrix[rows][colm];
        }
        result[rows] = calci;
        calci = 0;
    }
}

int main()
{
    int vector[3], matrix[3][3], result[3], rows, colm, x = 0, calci = 0;

    
    
    
    /**********************
      Reading the Matrices
    ***********************/



    printf("Enter vector parameters:\n");
    for (x = 0; x < 3; x++)
    {
        scanf("%d", &vector[x]);
    }



    for (rows = 0; rows < 3; rows++)
    {
        for (colm = 0; colm < 3; colm++)
        {
            printf("Enter the number - Matrix[%d][%d]\n", rows + 1, colm + 1);
            scanf("%d", &matrix[rows][colm]);
        }
    }




    /******************
    Printing the matrices
    *******************/



    printf("\nVector:\n");
    for (x = 0; x < 3; x++)
    {
        printf("\n %d, \n", vector[x]);
    }

    printf("\nMatrix:\n");
    for (rows = 0; rows < 3; rows++)
    {
        for (colm = 0; colm < 3; colm++)
        {
            printf("%d ", matrix[rows][colm]);
        }
        printf("\n");
    }

    multiplying(vector, matrix, result);

    printf("\nResult:\n");
    for (x = 0; x < 3; x++)
    {
        printf("\n %d \n", result[x]);
    }

    return 0;
}
