#include <stdio.h>
#include <string.h>
#include <math.h>

struct point
{
    int x;
    int y;
};

double distance(struct point a, struct point b)
{
    double distance;
    distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y-b.y) *(a.y-b.y));
    return distance;
}


int main(void)
{
    struct point p1 = { 5, 8 };
    struct point p2 = { -3, 3 };
    struct point p3 = { 0, 4 };
    struct point p4 = { 3, 0 };

    printf("%.3f\n", distance(p1, p2));
    printf("%.3f\n", distance(p3, p4));

    return 0;
}

