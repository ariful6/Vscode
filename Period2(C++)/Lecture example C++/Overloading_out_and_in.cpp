#include<iostream>
using namespace std;

class Point{
    friend istream &operator>>(istream &in, Point &p);
    friend ostream &operator<<(ostream &out, Point &p);
    public:
        Point(float x0 = 0.0, float y0 = 0.0);
    private:
        float x;
        float y;
};
int main(){
    Point p;
    cout << "Enter a point "<<endl;
    cin >> p;
    cout << "The point is " << p;
}
Point::Point(float x0, float y0){
    x = x0; y = y0;
}
istream &operator>>(istream &in, Point &p){
    cout <<"Enter x: ";
    in >> p.x;
    cout <<"Enter y: ";
    in >> p.y;
    return in;
}
ostream &operator<<(ostream &out, Point &p){
    out <<"("<< p.x <<"," << p.y <<")"<<endl;
    return out;
}