#include <stdio.h>

int *getMax(int *arr, int n);

int main(void){

    int maxValue;
    int array[6] = {3, 5, 2, 8, 6, 7};

    printf ("%d\n", *getMax(array, 6));

    maxValue = *getMax(array, 6);
    *getMax(array, 6) = *getMax(array, 6)*10;

}

int *getMax(int *arr, int n){

    int i, maxi = 0;

    for (i = 1; i < n; i++)
        if (arr[i] > arr[maxi])
            maxi = i;

   return &arr[maxi];

}