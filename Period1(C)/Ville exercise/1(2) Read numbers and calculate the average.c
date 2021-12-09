#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readint(void);

int main(void)
{
    int x = 0;
    int counter = 0;
    int  total = 0;
    float average = 0.0;
   
    for(int i = 0; i<25 ; i++)
    {
        x = readint();
        if (x>0)
        {
        counter++;
        total = total + x;
        average =  (float)total /(float) counter;
        }
        else
        break;
    }
    
    printf("%.4f\n", average);
    return 0;
}

int readint(void)
{
    int num;
    
    printf("Enter number: ");
    scanf("%d", &num);
    
    return num;
    
}
