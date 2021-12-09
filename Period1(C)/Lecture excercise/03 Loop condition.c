#include <stdio.h>
#define STUDENT_COUNT 20

int main(void)
{
    int grades[STUDENT_COUNT];
    int count;
    int i;
    
    printf("Enter number of students to initialize: ");
    scanf("%d", &count);
    for(i = 0; i < count && i< STUDENT_COUNT; i++)
    {
        printf("Enter grades for student number %d: ", i);
        scanf("%d", &grades[i]);
        printf("Student number: %d\t Grades: %d\n", i, grades[i]);
    }
    return 0;
}
