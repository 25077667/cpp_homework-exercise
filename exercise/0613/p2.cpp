#include <cmath>
#include <iostream>
using namespace std;

class Circle {
   public:
    Circle() { radius = area = 0; }
    Circle(double r) : radius(r) { setArea(r); }
    void output() { cout << "r = " << radius << endl
                           << "Area = " << area << endl; }
    void setArea(double r) { this->area = r * r * acos(-1); }
    double getArea() { return this->area; }
    double getRadius() { return this->radius; }

   private:
    double radius, area;
};

class Cylinder : public Circle {
   public:
    Cylinder() : Circle() { high = 0; }
    Cylinder(double r, double h) : Circle(r), high(h) {}
    /* void output() { cout << "r = " << getRadius() << endl
                           << "volume = " << getArea() * high << endl; }*/

   private:
    double high;
};

int main() {
    double r, h;
    cout << "Enter the radius: ";
    cin >> r;
    Circle A(r);
    A.output();

    cout << "Enter the high: ";
    cin >> h;
    Cylinder B(r, h);
    B.output();
    return 0;
}