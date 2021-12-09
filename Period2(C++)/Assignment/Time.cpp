#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Time.h"
using namespace std;

Time::Time(const int hour, int min):hour(hour), min(min){				//time initialize
}
void Time::read(const char *prompt){
	int n = 0;
	cout << prompt <<endl;
	while(n<=0){										//Asking user to enter time in right format
		cout << "Hour(24h): ";
		cin >> hour;
		cout << "Min(60min): ";
		cin >> min;
		if (hour >= 0 && hour <=23 && min >= 0 && min <= 60){		
			n++;
		}
		else{
			cout << "Wrong time format. Please type in (0 - 23)h and (0 - 60)min format" << endl;	
		} 
	}
}
Time Time::operator-(const Time &t)const{
    Time a; int b;
    b = (hour * 60 + min) - (t.hour * 60 + t.min);
    a.hour = b / 60;
    a.min = b % 60;
    return a;
}
Time Time::operator+(const Time &t)const{
    Time a; int b;
    b = (hour * 60 + min) + (t.hour * 60 + t.min);
    a.hour = b / 60;
    a.min = b % 60;
    return a;
}
Time &Time::operator++(){
    min++;
    return *this;
}
Time Time::operator++(int){
    Time old = *this;
    min++;
    return old;
}
ostream &operator<< (ostream &out, const Time &t){
    cout << setiosflags(ios::right);
    cout << setfill('0') << setw(2) << t.hour;
    cout << ":" << setfill('0') << setw(2) << t.min <<endl;
	return out;
}
istream& operator>>(istream& in, Time& s) {
    char ch;
    in >> s.hour >> ch >> s.min;
    return in;
}
bool Time::operator<(const Time &t)const{
    if (hour < t.hour || (hour == t.hour && min < t.min)) {
        return true;
    }
    else{
        return false;
    }
}
bool Time::operator>(const Time &t)const{
    if (hour < t.hour || (hour == t.hour && min < t.min)) {
        return false;
    }
    else{
        return true;
    }
}