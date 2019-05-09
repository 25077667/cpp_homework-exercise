#include <bits/stdc++.h>
using namespace std;
class Pair {
    int first, second;

   public:
    Pair() {}
    Pair(int x, int y) : first(x), second(y) {}
    Pair& operator++();
    Pair operator++(int);
    Pair& operator--();
    Pair operator--(int);
    friend const Pair operator+(const Pair&, const Pair&);
    friend const Pair operator-(const Pair&, const Pair&);
    friend const Pair operator*(const Pair&, const Pair&);
    friend const Pair operator/(const Pair&, const Pair&);
    friend istream& operator>>(istream& input, Pair& p) {
        cout << "enter a pair";
        cin >> p.first >> p.second;
        return input;
    }
    friend ostream& operator<<(ostream& output,const Pair& p) {
        output << "(" << p.first << "," << p.second << ")" << endl;
        return output;
    }
};
int main() {
    Pair A, B;
    cin >> A >> B;
    cout << A << B;
    cout << A++ << ++A << A-- << --A << endl;
    A = A+B;
    cout << A ;
    A = A-B;
    cout << A;
    A = A*B;
    cout << A;
    A = A/B;
    cout << A;
    return 0;
}

Pair& Pair::operator++() {
    this->first++;
    this->second++;
    return *this;
}
Pair Pair::operator++(int) {
    Pair tmp(first, second);
    first ++;
    second ++;
    return tmp;
}
Pair& Pair::operator--() {
    this->first--;
    this->second--;
    return *this;
}
Pair Pair::operator--(int) {
    Pair tmp(first, second);
    first --;
    second --;
    return tmp;
}

const Pair operator+(const Pair& p1, const Pair& p2) {
    return Pair(p1.first + p2.first, p1.second + p2.second);
}
const Pair operator-(const Pair& p1, const Pair& p2) {
    return Pair(p1.first - p2.first, p1.second - p2.second);
}
const Pair operator*(const Pair& p1, const Pair& p2) {
    return Pair(p1.first * p2.first - p1.second * p2.second, p1.second * p2.first + p1.first * p2.second);
}
const Pair operator/(const Pair& p1, const Pair& p2) {
    return Pair((p1.first * p2.first + p1.second * p2.second) / (p2.first * p2.first + p2.second * p2.second),
                (p1.second * p2.first - p1.first * p2.second) / (p2.first * p2.first + p2.second * p2.second));
}