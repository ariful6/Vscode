#include<iostream>
using namespace std;

class Time{                             //class defination
    public:
        Time diff(Time t2);
    private:
        int hour;
        int min;    
};

int main(){                                         //applicaiton
    Time time1, time2, difference;                  //variables

    difference = time1.diff(time2);

    return 0;
}
//operation funcitons implementations
Time Time::diff(Time t2){
    Time aux;
    int dmin, t1min, t2min;

    t1min = hour * 60 + min;                    //target object
    t2min = t2.hour * 60 + t2.min;              //parameter object
    dmin = t1min - t2min; 
    aux.hour = dmin / 60;                       //local object
    aux.min = dmin % 60;                         //local object
    return aux;
}