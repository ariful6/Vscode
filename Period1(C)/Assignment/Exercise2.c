#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    float arr[12] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}; //array initialize
    float gross = 0.0;
    float total = 0.0;
    float element_6 = 0.0;
    float average = 0.0;
    
    int i;
    
    printf("Enter a gross income: ");       //ask user to enger gross income
    scanf("%f", &gross);
    
    average = gross / 12.5;
    element_6 = (gross/12.5)*1.5;
    
    arr[6] = element_6;                    //put value on 6 elements of array
    
    for(i = 0; i<6; i++)                //put value 0-5 elements of arry
    {
        arr[i] = average;
    }
    for(i = 7; i<12; i++)              //put value 0-5 elements of arry
    {
        arr[i] = average;
    }
    
    for (i = 0; i<12; i++)             //calculates total
    {
        total += arr[i];
    }
    
    for(i = 0; i<12;i++)                //prints all the elements in array
    {
        printf("element[%2d] = %15.4f\n", i, arr[i]);
    }
    
    printf("Total       = %15.4f\n", total);    
}
