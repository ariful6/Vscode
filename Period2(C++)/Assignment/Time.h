#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>
using namespace std;

class Time{
    friend ostream& operator<<(ostream& out, const Time& t);
    friend istream& operator>>(istream& in, Time& s);

public:
    Time(int hour1 = 0, int min1 = 0);
    bool operator<(const Time& t) const;
    Time operator+(const Time& t) const;
    Time operator-(const Time& t) const;
    Time& operator++();
    Time operator++(int);
    void read(const char* prompt);
    bool operator>(const Time& t) const;
    bool operator==(const Time& t) const;

private:
    int hour;
    int min;
};

#endif // !TIME_H_INCLUDED