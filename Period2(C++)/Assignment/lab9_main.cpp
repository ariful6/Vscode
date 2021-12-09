#include <iostream>
#include <vector>
using namespace std;

//definition of class Point
class Point {
public:
    //constructor
    Point(double xcoord = 0.0, double ycoord = 0.0){
        x = xcoord; y = ycoord;
    };
    // destructor
    virtual ~Point() = default;
    virtual void input(const char* prompt);                                         //ask values from user  
    virtual void output() const;                                                    //print coordinates and area
    virtual double area() const{return 0;};                                         //return area    
    void move(double deltax, double deltay){};
private:
    double x;
    double y;
};

class Circle : public Point{                    //derived class circle
public:
    Circle(double xcoord1 = 0.0, double ycoord1 = 0.0, double radius1 = 0.0){
        x1 = xcoord1; y1 = ycoord1; radius = radius1;
    };
    virtual ~Circle() = default;
    virtual double area()const;
    virtual void output() const;
    virtual void input(const char* prompt);
private:
    float radius;
    double x1;
    double y1;
};

class Square : public Point {                   //dervied class square
public:
    Square(double xcoord2 = 0.0, double ycoord2 = 0.0, double width1 = 0.0, double height1 = 0.0){
        x2 = xcoord2; y2 = ycoord2; width = width1; height = height1;
    };
    virtual ~Square() = default;
    virtual double area()const;
    virtual void output() const;
    virtual void input(const char* prompt);
private:
    double width;
    double height;
    double x2;
    double y2;
};

int main() {
    //variable declariton
    vector<Point*>Vector;
    Point *p1 = new Point();
    Circle *c1 = new Circle();
    Square *s1 = new Square();
    
    //variable initialization
    *p1 = {1.0, 1.0};
    *c1 = {2.0, 2.0, 2.0};
    *s1 = {5.0, 5.0, 2.0, 2.0};
    
    //adding points to the pointer vector
    Vector.push_back(p1);
    Vector.push_back(c1);
    Vector.push_back(s1);
    p1->output();
    c1->output();
    s1->output();
    //sorting vector
    sort(Vector.begin(), Vector.end());
    p1->output();
    s1->output();
    c1->output();
    //asking user for the input
    p1->input("enter");
    c1->input("enter");
    s1->input("enter");
    //printing
    p1->output();
    c1->output();
    s1->output();
    sort(Vector.begin(), Vector.end());
    
    return 0;
}


void Point::output() const{
    cout <<"Coordinates: (" << x << "," << y <<")"<<endl;
}
void Circle::output() const{
    cout <<"Circle's area: " << area()<<" ";
    cout <<"Coordinates: (" << x1 << "," << y1 <<")"<<endl;
}
void Square::output() const{
    cout <<"Square's area: " << area()<<" ";
    cout <<"Coordinates: (" << x2 << "," << y2 <<")"<<endl;
}
double Circle::area()const{
    const float pi = 3.14159f;
    return pi * radius * radius;
}
double Square::area()const{
    return width* height;
}
void Point::input(const char* prompt){
    cout << "Point:"<<endl;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
}
void Circle::input(const char* prompt){
    cout << "Circle:"<<endl;
    cout << "Enter x: ";
    cin >> x1;
    cout << "Enter y: ";
    cin >> y1;
    cout << "Enter radius: ";
    cin >> radius;
}
void Square::input(const char* prompt){
    cout << "Sqaure:"<<endl;
    cout << "Enter x: ";
    cin >> x2;
    cout << "Enter y: ";
    cin >> y2;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter height: ";
    cin >> width;
}