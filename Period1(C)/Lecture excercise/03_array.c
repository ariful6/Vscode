#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int grades [20];
    int index;
    int value;
    
    printf("Enter a student number: ");
    scanf("%d", &index);
    if(index>=0 && index<20){
        printf("Enter grade for the student number %d: ",index);
        scanf("%d", &value);
        grades [index] = value;
        printf("Student : %d\t Grade : %d\n", index, grades[index]);
    }
    else
    {
        printf("You entered a invalid ID \n");
    }
    return 0;
}
