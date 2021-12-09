#include <stdio.h>
#include <stdlib.h>

#define GRADE_MAX 5
#define GRADE_MIN 0
#define STUDENT_NR 45000
#define ARRAY_SIZE 100

float average (int number, int grades[]);

int main (void)
{
    //initialize variables
    int index = 0;
    int numberOfStudent = 0;
    int student_nr = 0;
    int grades[ARRAY_SIZE] ={};
    int value = 0;
    float average_grades = 0.0;
    
    printf("Enter the number of students to be graded (max 100): ");         //ask user to enter number of students
    scanf("%d", &numberOfStudent);
   
    while (numberOfStudent<0 || numberOfStudent>100)                 // check for right input
    {
        printf("Student amount should be between 0-100\n");
        printf("Enter the number of students to be graded (max=100): ");
        scanf("%d", &numberOfStudent);
    }
    for (index = 0;  index<numberOfStudent; index++)
    {
        student_nr = index + STUDENT_NR;
        printf("Enter the grade(0-5) for student nr: %d = ", student_nr);
        scanf("%d", &value);
            while(value < GRADE_MIN || value > GRADE_MAX)     //check for right grade input
            {
                printf("Only 0-5 accepted\n");
                printf("Enter the grade(0-5) for student nr: %d = ", student_nr);
                scanf("%d", &value);
            }
        grades[index] = value;
    }
    average_grades = average(numberOfStudent, grades);
    printf("Average course grades: %.2f\n", average_grades);            //prints average grades upto 2 decimal values
}

float average (int number, int grades[])                            //Funtions returns floating value
{
    //intializing value for the local variable
    int i;
    int total = 0;
    float average = 0.0;
    
    
    for (i = 0; i<number; i++)
    {
        total += grades[i];                                 //adding the grades to total
        average = (float)total/(float)number;
    }
    return average;
}
