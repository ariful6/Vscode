#include <iostream>

using namespace std;

class Point{
    public:
        Point (float x0=0.0, float y0=0.0);
        void read();
        void print();
    private:
        float x;
        float y;
};

class Circle{
    public:
        Circle (float x0=0.0, float y0=0.0, float r0=0.0);
        Circle (const Point &cp0, float r0=0.0);
        void read();
        void print();
    private:
        float radius;
        Point centerPoint;    
};

int main(){
    Point p(11.0, 12.0);
    Circle c1, c2(1.0, 2.0, 10.0),
           c3(p, 20.0);
    c1.print();
    c2.print();
    c3.print();       

    return 0;
}

Point::Point (float x0, float y0){
    x = x0;
    y = y0;
}
void Point::read(){
    cout << endl << "x-coordinate: ";
    cin >> x;
    cout << "y-coordinate: ";
    cin >> y;
}
void Point::print(){
    cout << "("  << x << "," << y <<")";
}
Circle::Circle(float x0, float y0, float r0):centerPoint(x0, y0){
    radius = r0;
}
Circle::Circle (const Point &cp0, float r0):centerPoint(cp0){
    radius = r0;
}
void Circle::read(){
    cout << "\nEnter radius: ";
    cin >> radius;
    cout << "Enter centerpoint: ";
    centerPoint.read();
}
void Circle:: print(){
    cout << "\nThe circle data is : ";
    cout << "\nRadius is : " << radius;
} 