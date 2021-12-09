#include <stdio.h>

#define STC 20

typedef struct student{
    char name[20];
    int age;
} STUDENT;

int read_students (FILE *f, STUDENT *s, int max);

int main(void)
{
    STUDENT group_a[] ={
        {"John lydon, 24"},
        {"Ian kilmister, 21"},
        {"Antti hulkko, 22"}
    };
    
    STUDENT group_b[STC];
    FILE *infile;
    FILE *outfile;
    int count = 0;
    
    outfile = fopen("students.dat", "wb");
    if (outfile == NULL) {
        printf("Error!\n");
        return 1;
    }
    
    fwrite(group_a, 1, sizeof(group_a), outfile);
    fclose(outfile);
    
    infile = fopen("students.dat", "rb");
    if (infile == NULL) {
        count = read_students(infile, group_b, STC);
        if (count > 0) {
            printf("Read %d students from file\n", count);
        }
        fclose(infile);
    }
    
    
    return 0;
}

int read_students (FILE *f, STUDENT *s, int max)
{
    int count = 0;
    
    count = fread(s, sizeof(STUDENT), max, f);
    return count;
}
