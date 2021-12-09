#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include<iomanip>
#include "Time.h"

using namespace std;

class Day {
public:
    Day(int day0 = 0, string month0 = "");
    bool from_str(const string &s);
    string to_str();
    void dst(int offset);
private:
    int day;
    string month;
    vector<Time> list;
};


int main()
{
    ifstream inputFile("calendar.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string line;
    vector<Day> cal;
    Day day;

    while (getline(inputFile, line)) {
        if (day.from_str(line)) {
            cal.push_back(day);
        }
    }
    cout << "Calendar" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    // DST shift
    for (auto& e : cal) {
        e.dst(1);
    }
    cout << "DST" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    cout << "End" << endl;

    return 0;
}

Day::Day(int day0, string month0) :day(day0), month(month0){}

bool Day::from_str(const string& s) {
    int userDay;
    string userMonth;
    Time userTime;
    list.clear();
    istringstream sin(s);

    sin >> userDay;
    sin >> userMonth;
    sin >> userTime;
    if (!sin) {
        return false;
    }
    else {
        day = userDay;
        month = userMonth;
        list.push_back(userTime);
        while (sin >> userTime) {
            list.push_back(userTime);
        }
        sort(list.begin(), list.end());
        return true;
    }
}
string Day::to_str() {
    ostringstream out;
    out << day << " " << month <<" ";
    for (auto& n : list) {
        out << n << " ";
    }
    return out.str();
}

void Day::dst(int offset) {
    for (auto& t : list) {
        if (t + offset > 23) {
            t = t + offset - 24;
        }
        else {
            t = t + offset;
        }
    }
    sort(list.begin(), list.end());
}


