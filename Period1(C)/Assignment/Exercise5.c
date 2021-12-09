#include <stdio.h>


void multiplication(int vector[3], int metrix[3][3], int resultMatrix[3]);

int main (void)
{
    int i, j;
    int vector[3], metrix[3][3], resultMatrix[3];
    
    printf("Enter the 3 element vector : \n");           //ask user to input vector
    for (int i = 0; i < 3 ; i++)
    {
        printf("Vector element %d = ",i+1);
        scanf("%d", &vector[i]);                //put vector in vector arry
    }
    
    printf("Enter the 3 by 3 matrix :\n"); //ask user to input matrix
    for( i = 0; i <3 ; i++)               // for rows
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Matrix element a%d %d : ", i+1, j+1);
            scanf("%d", &metrix[i][j]);
        }
    }
    
    //printing vector
    printf("\nVector : \n%d\t%d\t%d\n", vector[0], vector[1], vector[2]);
    
    //printing Matrix
    printf("\nMatrix : \n");
    for( i = 0; i <3 ; i++){
        for (j = 0; j < 3; j++){
            printf("%d\t", metrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    multiplication(vector, metrix, resultMatrix);
    
    // printing result
    printf("Result: \n");
    for (i = 0; i < 3; i++) {
            printf("%d\n", resultMatrix[i]);
        }
        printf("\n");
}
    
void multiplication(int vector[3], int metrix[3][3], int resultMatrix[3])
{
    int rows, colm, sum = 0;
    for (rows = 0; rows < 3; rows++){
        for (colm = 0; colm < 3; colm++) {
            sum += vector[colm] * metrix[rows][colm];
        }
        resultMatrix[rows] = sum;
        sum = 0;                        //reset the sum to 0
    }
}
