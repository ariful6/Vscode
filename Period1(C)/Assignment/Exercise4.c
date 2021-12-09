#include <stdio.h>

#define HOURS_MIN  1440                                     //24*60

int main (void)
{
    //initialize all variables
    int hh = 0, mm = 0, enterTime = 0;
    int h_sleep = 0, mm_sleep = 0, sleepTime = 0;
    int totalMin = 0;
    int wakeHour = 0, wakeMin = 0;
    
    printf("Enter current time (hh:mm) : ");
    scanf("%d : %d", &hh, &mm);
   
    while(hh>24 || hh <0 || mm > 60 || mm<0 )     //printing invalid time error
    {
        printf("Invalid time format\n");
        printf("Enter current time (hh:mm) : ");
        scanf("%d : %d", &hh, &mm);
    }

    printf("How long do you want to sleep (h:mm) : ");
    scanf("%d : %d", &h_sleep, &mm_sleep);
    
    while(h_sleep>24 || h_sleep <0 || mm_sleep > 60 || mm_sleep<0 )     //printing invalid time format error
    {
        printf("Invalid time format\n");
        printf("How long do you want to sleep (h:mm) : ");
        scanf("%d : %d", &h_sleep, &mm_sleep);
    }
    
    enterTime = hh*60 + mm;
    sleepTime = h_sleep*60+ mm_sleep;
    totalMin = enterTime + sleepTime;
    
    if (totalMin>=HOURS_MIN)                        //correcting 24h format
    {
        totalMin = totalMin - HOURS_MIN;
        wakeHour = totalMin / 60;
        wakeMin  = totalMin % 60;
    }
    else
    {
    wakeHour = totalMin / 60;
    wakeMin  = totalMin % 60;
    }

    printf("If you go to bed now you must wake up at %d:%d\n", wakeHour, wakeMin);  //print wake up time
}
