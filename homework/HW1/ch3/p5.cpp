#include <bits/stdc++.h>
using namespace std;
class Info {
   public:
    Info() : height(0), weight(0), age(0) {}
    double hat_size() { return weight / height * 2.9; };
    double Jacket_size() { return height * weight / 288 + ((age > 30) ? (double)((int)((age - 30) / 10) * 0.125) : 0); };
    double waist() { return weight / 5.7 + ((age > 28) ? (double)((int)((age - 28) / 2) * 0.1) : 0); };
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
        output << "Hat size = " << people.hat_size() << " in inches." << endl
               << "Jacket size (chest in inches) = " << people.Jacket_size() << " (chest in inches)" << endl
               << "Waist = " << people.waist() << " in inches." << endl;
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