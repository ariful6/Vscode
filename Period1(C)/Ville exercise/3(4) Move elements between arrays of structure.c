#include <stdio.h>

#define MAX_LEN 32

typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
} student;

int move(student *source, int group, student *target, int size);

int main()
{

    return 0;
}

int move(student *source, int group, student *target, int size)
{
    int target_elements = 0;
    int last_element,i =0;
    while (target[target_elements].id != 0)
    {
        target_elements++;
    }
    
    last_element=target_elements;
    target_elements=0;
        
    while(source[i].id !=0)
    {
        if(source[i].group == group && last_element< size-1)
        {
            target[last_element] = source[i];
            target[last_element + 1].id =0;
            last_element++;
            
            for(int x = i; source[x].id != 0;x++)
            {
                source[x] = source[x+1];
            }
            i=0;
            target_elements++;
        }
        i++;
        
    }
    return target_elements;
}
