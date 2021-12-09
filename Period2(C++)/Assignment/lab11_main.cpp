#include <iostream>
using namespace std;

class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
    //virtual void SetObserver(CounterObserver *) = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};
class CounterObserver {
public:
virtual void HandleLimitReached(Counter *ctr) = 0;
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
        void SetObserver(Observer* obs_ptr);
	private:
		int limit1;
		int counterValue1;
        Observer* obs;
        void notify();
};
class Observer {
public:
    virtual void HandleLimitReached() = 0;
};
class CounterUser : public Observer{                                                        //CounterUSer class
public:
    CounterUser(int limit);
    ~CounterUser() = default;
    void IncrementBy(int n);
    void HandleLimitReached();
private:
    OverflowCounter* of_counter;
};

int main(int argc, char** argv) {
    CounterUser cu(5);
    cu.IncrementBy(12);                                                                     //OUTPUT: two times "Limit has been reached"  	
    CounterUser cu2(9);
    cu2.IncrementBy(9);
    cout << "Just passing time" << endl;
    cu2.IncrementBy(1);                                                                     //OUTPUT: "Limit has been 
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
    obs = nullptr;
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
void OverflowCounter::SetObserver(Observer* obs_ptr){
	obs = obs_ptr;
}
void OverflowCounter::notify(){
	obs->HandleLimitReached();
}
//methods of CounterUser
CounterUser::CounterUser(int limit){
	of_counter = new OverflowCounter(0, limit);
	of_counter->SetObserver(this);
}
void CounterUser::IncrementBy(int n){
	for (int i = 0; i < n; i++){
		of_counter->inc();
	}
}
void CounterUser::HandleLimitReached(){
	cout << "Limit has been reached." << endl;
}