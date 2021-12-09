#include <stdio.h>

struct student {
    char name[20];
    int age;
};

typedef struct course{
    char name[20];
    char id[20];
    int points;
} COURSE;

int main(void)
{
    int sizes[8] = {0};
    int count;
    COURSE cc[2];
    struct student st;
    
    sizes[0] = sizeof(int);
    sizes[1] = sizeof(long);
    sizes[2] = sizeof(sizes);
    sizes[3] = sizeof(COURSE);
    sizes[4] = sizeof(struct student);
    sizes[5] = sizeof(cc);
    sizes[6] = sizeof(st);
    sizes[7] = sizeof(double);
    
    for (count = 0; count < 8; count++) {
        printf("Sizes [%d] = %d\n", count, sizes[count]);
    }
}
