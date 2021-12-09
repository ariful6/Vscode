#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char name[20];
    int age;
} STUDENT;

int main(void)
{
    STUDENT group[] ={
        {"John lydon", 24},
        {"Ian kilmister", 21},
        {"Antti hulkko", 22}
    };

    int i;
    int students;
    
    students = (sizeof(group)/sizeof(STUDENT));
    
    for( i = 0; i < students; i++){
        printf("Name: %s\t    Age: %d\n", group[i].name, group[i].age);
    }
    
    return 0;
}

