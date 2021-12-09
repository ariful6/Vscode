#include<iostream>
using namespace std;

class Person{                           //class defination
    public:
        void read();
        void print();
        void getOlder(int years);
    private:
        char name[30];
        int age;
};

int main(){                             //application

    Person matti, maija;

    matti.read();
    matti.getOlder(1);
    matti.print();

    return 0;
}
//operation function implementation
void Person::read(){
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}
void Person::print(){
    cout << "Personal data is: ";
    cout << name;
    cout << " "<< age <<endl;
}
void Person::getOlder(int years){
    age = age + years;
}