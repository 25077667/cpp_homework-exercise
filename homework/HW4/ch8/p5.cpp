#include <iostream>
#include <utility>
using namespace std;
class Vector2D {
   public:
    Vector2D(int, int);
    ~Vector2D() {}
    friend const int operator*(const Vector2D& a, const Vector2D& b);
    friend ostream& operator<<(ostream& output, const Vector2D& thisVector2D);

   private:
    pair<int, int> p;
};
int main() {
    Vector2D a1(9, 10), a2(17, 0);
    cout << a1 << " * " << a2 << " = " << a1 * a2 << endl;
    Vector2D b1(10, 12), b2(0, 8);
    cout << b1 << " * " << b2 << " = " << b1 * b2 << endl;
    Vector2D c1(19, 13), c2(7, -20);  //must an int smaller then 20
    cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;
    return 0;
}
Vector2D::Vector2D(int x, int y) {
    p.first = x;
    p.second = y;
}
const int operator*(const Vector2D& a, const Vector2D& b) {
    return a.p.first * b.p.first + a.p.second * b.p.second;
}
ostream& operator<<(ostream& output, const Vector2D& thisVector2D) {
    output << "(" << thisVector2D.p.first << "," << thisVector2D.p.second << ")";
    return output;
}