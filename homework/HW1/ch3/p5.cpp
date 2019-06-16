#include <bits/stdc++.h>
using namespace std;
class Info {
   public:
    Info() : height(0), weight(0), age(0) {}
    double calculateHatSize() { return weight / height * 2.9; };
    double calculateJacketSize() { return height * weight / 288 + ((age > 30) ? (double)((int)((age - 30) / 10) * 0.125) : 0); };
    double calculateWaist() { return weight / 5.7 + ((age > 28) ? (double)((int)((age - 28) / 2) * 0.1) : 0); };
    friend istream& operator>>(istream& input, Info& people) {
        cout << "please input your height:";
        input >> people.height;
        cout << "please input your weight:";
        input >> people.weight;
        cout << "please input your age:";
        input >> people.age;
        return input;
    }
    friend ostream& operator<<(ostream& output, Info& people) {
        output << "Hat size = " << people.calculateHatSize() << " in inches." << endl
               << "Jacket size (chest in inches) = " << people.calculateJacketSize() << " (chest in inches)" << endl
               << "Waist = " << people.calculateWaist() << " in inches." << endl;
        return output;
    }

   private:
    double height;
    double weight;
    int age;
};
int main() {
    char tmp;
    while (cout << "y is continue, q is quit" && cin >> tmp && tmp == 'y') {
        Info people;
        cin >> people;
        cout << people;
    }
    return 0;
}