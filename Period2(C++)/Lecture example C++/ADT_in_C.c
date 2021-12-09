#include<stdio.h>

typedef struct {                                        //datatype defination
    float x;
    float y;
}Tpoint;

void read_point(Tpoint *p, char *prompt);               //operation function prototypes
void print_point(Tpoint p);
float calculate_dist(Tpoint p1, Tpoint p2);

int main(){
    Tpoint p1, p2;
    float dist;
    read_point(&p1, "Enter point 1: ");
    read_point(&p2, "Enter point 2: ");
    dist = calculate_dist(p1, p2);
    printf("Distance is %f", dist);  

    return 0; 
}
//Operation funtion implementation
void read_point(Tpoint *p, char *prompt){
    printf("\n%s", prompt);
    scanf("%f", & p->x);
    scanf("%f", & p->y);
}
void print_point(Tpoint p){

}
float calculate_dist(Tpoint p1, Tpoint p2){

    
}