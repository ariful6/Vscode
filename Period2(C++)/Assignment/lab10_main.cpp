#include <iostream>
using namespace std;


class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};
class LimitedCounter : public Counter{
	public:
		LimitedCounter (int initialValue = 0, int upperLimit = 0);
		virtual ~LimitedCounter() = default;										//deconstractor
		virtual void inc();
		virtual void dec();
		virtual operator int(){return counterValue;};
	private:
		int limit;
		int counterValue;
};
class OverflowCounter : public Counter{
	public:
		OverflowCounter (int initialValue = 0, int upperLimit = 0);
		virtual ~OverflowCounter() = default;										//deconstractor
		virtual void inc();
		virtual void dec();
		virtual operator int(){return counterValue1;};
	private:
		int limit1;
		int counterValue1;
};

void UseCounter(Counter& ctr, int num);

int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	cout << oc << endl;
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.dec();
	cout << oc << endl; // should display 8

	cout << lc << endl;
	lc.inc();
	cout << lc << endl;
	lc.dec();
	cout << lc << endl;
	for(int i = 0; i < 10; ++i) lc.inc();
	cout << lc << endl;
	UseCounter(lc, -9);
	cout << lc << endl;

	return 0;
}
//methods of LimitedCounter
LimitedCounter::LimitedCounter (int initialValue, int upperLimit){
	counterValue = initialValue;
	limit = upperLimit;
}
void LimitedCounter::inc(){
	if (counterValue < limit)
		counterValue++;
}
void LimitedCounter::dec(){
	if (counterValue > limit)
		counterValue--;
}
//methods of OverflowCounter
OverflowCounter::OverflowCounter (int initialValue, int upperLimit){
	counterValue1 = initialValue;
	limit1 = upperLimit;
}
void OverflowCounter::inc(){
	counterValue1++;
	if (counterValue1 <= limit1)
		counterValue1 = 0;
}
void OverflowCounter::dec(){
	counterValue1--;
	if (counterValue1 <= 0)
		counterValue1 = limit1;
}
void UseCounter(Counter& ctr, int num){											//implementation of function
	bool is_inc = true;
	if (num < 0){
		is_inc = false;
	}
	for (int i = 0; i < abs(num); i++){
		if (is_inc)
			ctr.inc();
		else
			ctr.dec();
	}
}