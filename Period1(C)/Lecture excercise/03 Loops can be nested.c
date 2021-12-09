#include <stdio.h>
#define GRADE_MAX 5
#define GRADE_MIN 0
#define STUDENT_COUNT 20

int main(void)
{
    int grades[STUDENT_COUNT];
    int student_nr;
    int value;
    
    for(student_nr = 0; student_nr < STUDENT_COUNT; student_nr++)
    {
        printf("Enter grade for student %d: ", student_nr);
        scanf("%d", &value);
        while(value < GRADE_MIN || value > GRADE_MAX)
        {
        printf("Grade must be in range %d to %d\n", GRADE_MIN, GRADE_MAX);
        printf("Enter grade: ");
        scanf("%d", &value);
        }
        grades[student_nr] = value;
    }
    return 0;
}
