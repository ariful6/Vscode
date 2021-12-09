#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Tpoint{                        //class defination
    private:
        float x;
        float y;
    public:
        void read(const char *prompt);
        void print();
        float calculate_dist(Tpoint p2);
};

int main(void){
    Tpoint p1, p2;
    float dist;

    p1.read("Enter point 1: ");
    p2.read("Enter point 2: ");
    dist = p1.calculate_dist(p2);
    cout << "Distance is " << dist<<endl;

    return 0;
}
//operation function implementation
void Tpoint::read(const char *prompt){
    cout << prompt;
    cin >> x;
    cin >> y;
}
void Tpoint::print(){

}

float Tpoint::calculate_dist(Tpoint p2){

 }