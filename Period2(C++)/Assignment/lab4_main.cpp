#include<iostream>
#include<iomanip>

using namespace::std;

class Time{											//Class defination
	public:
		void read(const char *prompt);
		bool lessThan(Time t);
		Time subtract(Time t);
		void display();
	private:
		int hour;
		int min;			
};

int main() {										//Applicaiton
	Time time1, time2, duration;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1.lessThan(time2)) {
		duration = time2.subtract(time1);
		cout << "Starting time was ";
		time1.display();
	} else {
		duration = time1.subtract(time2);
		cout << "Starting time was ";
		time2.display();
	}
	cout << "Duration was ";
	duration.display();

	return 0;
}
//Operation function implementation
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
bool Time::lessThan(Time t){
	if (hour < t.hour || (hour == t.hour && min < t.min)){				//Camparing time
		return true;
	}
	else{
		return false;
	}
}
Time Time::subtract(Time t){										//subtraction
	Time a; int b = 0;
    b = (hour * 60 + min) - (t.hour * 60 + t.min);
    a.hour = b / 60;
    a.min = b % 60;
    return a;
}		
void Time::display(){												//display 
    cout << setiosflags(ios::right);
    cout << setfill('0') << setw(2) << hour;
    cout << ":" << setfill('0') << setw(2) << min <<endl;
}