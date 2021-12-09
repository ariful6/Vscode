#include <stdio.h>
#define STUDENT_COUNT 20

int main(void)
{
    int grades[STUDENT_COUNT];
    int index;
    int value;
    
    printf("Enter a student number : ");
    scanf("%d", &index);
    if (index>=0 && index<STUDENT_COUNT)
    {
        printf("Enter grade for the student number %d : ", index);
        scanf("%d", &value);
        grades[index] = value;
        printf("Student: %d\t, Grade: %d\n", index, grades[index]);
    }
    else
    {
        printf("Student number must be in range of 0 to %d\n", STUDENT_COUNT-1);
    }
}
