#include <stdio.h>

int main (void)
{
    int  counter = 0;
    float entered = 0, average = 0, total = 0;
  
    
    while(1)
    {
        printf("Enter number : ");
        scanf("%f", &entered);
        
        if (entered>0)                                //only for positive numbers
        {
            counter++;
            total = total + entered;
            average = (float)total / (float)counter;
            printf("Average number : %.2f\n", average);
        }
        else if (entered<0)                            // if the number is negative gives feedback
        {
            printf("Only positive numbers are accepted!\n");
        }
        else
        {
            printf("Average number : %.2f\n", average);       //for 0 only show average
        }
        
        return 0;
    }

    
}

