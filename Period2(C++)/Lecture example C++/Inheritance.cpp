#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

class Point{                                                     //defination of class "Point"
    public:
        Point (float xcoord=0.0, float ycoord=0.0);              //constractor
        Point (const Point &p);                                  //copy constractor
        virtual ~Point() = default;                              //Must have a virtual destractor if we want this class to be base class of other classes         
        virtual void read(const char *prompt);                   //Member funtions that are to be overriden in derived class must be declared "virtual"
        float getx() const;
        float gety() const;
        void move (float deltax, float deltay);
        virtual float distance (const Point &p2) const;
    private:
        float x; 
        float y;       
};
class Circle: public Point{                                    //defination of class "Circle"
    public:
        Circle (float cpx=0.0, float cpy=0.0, float r0=1.0);
        Circle (const Point &cp, float r0);                     //constractor 2
        Circle (const Circle &c);                              //copy constractor 
        virtual void read(const char *prompt) override;        //overrides the read funtion on Point class
        float getRadius() const;
        virtual float distance (const Circle &p2) const;
        float area() const;
    private:
        float radius;    
};
//prototypes of input and output operators
ostream &operator<<(ostream &out, const Point &p);
ostream &operator<<(ostream &out, const Circle &c);

int main(){
    Point p, p3(3.0, 3.0);
    Circle c1, c2(2.0, 2.0, 20.0), c3(p3, 30);

    c1.read("Enter circle 1");
    cout << c1 << endl;
    cout << "Center point of c1 is " << "(" << c1.getx() << ", " << c1.gety() <<")" << endl;
    cout << c3 << endl;
    cout << " Area of circle 3 is " << c1.area() << endl;
    cout << "\nDistance between circles is " << c1.distance(3) << endl;
    c3.move (0.5, 0.5);
    cout << c3 << endl;

    //c1 = p;                                                            //this is not possible, it causes compilation error
    p = c1;                                                              //circle can be assing to a point (though it makes no sesnse)
    cout << "Circle 1 as a point is " << p << endl;
    p.move(0.5, 0.5);
    cout << c1 << endl;                                                 //c1 is not moved
    cout << "point is moved" << p << endl;                              //p is moved
    //cout << p.area();                                                   //this is not possible, gives compilation error    

}
//Methods of class Point
Point::Point (float xcoord, float ycoord){
    x = xcoord;
    y = ycoord;
}
Point::Point (const Point &p){
    x = p.x;
    y = p.y;
}
void Point::read(const char *prompt){
    cout << prompt;
    cout << "\nEnter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
}
float Point::getx()const{
    return x;
}
float Point::gety()const{
    return y;
}
void Point::move (float deltax, float deltay){
    x+=deltax;
    y+=deltay;
}
float Point::distance (const Point &p2)const{
    return sqrt((p2.x-x)*(p2.x-x)+ (p2.y-y)*(p2.y-y));
}
//Methods of class circle
Circle::Circle (float cpx, float cpy, float r0) : Point(cpx, cpy), radius(r0){}
Circle::Circle (const Point &cp, float r0) : Point (cp), radius(r0){}
Circle::Circle (const Circle &c) : Point (c), radius(c.radius){}
void Circle::read(const char *prompt){
    cout << prompt;
    Point::read("\nEnter center point: ");
    cout << "Enter radius ";
    cin >> radius;
}
float Circle::getRadius()const{
    return radius;
}
float Circle::distance(const Circle &p2)const{
    float dist;
    dist = Point::distance(p2);                                 //use funtionality from the base class
    dist = dist - radius - p2.radius;                           //add some new funtionality
    return dist < 0 ? 0 : dist;
}
float Circle::area(void) const {
    float area;
    area = M_PI * radius * radius;
    return area;
}
//output operator funtions ( they are not friends now)
ostream &operator<<(ostream &out, const Point &p){
    out << "(" << p.getx() << "," << p.gety() << ")";
    return out;
}
ostream &operator<<(ostream &out, const Circle &c){
    out << "\nCircle: Radius is " << c.getRadius() << "\nCenter point is " << (Point)c; //static_cast<Point>(c)
    return out;
}