#include <bits/stdc++.h>
using namespace std;
class info {
   public:
    double hat_size() { return weight / height * 2.9; };
    double Jacket_size() { return height * weight / 288 + ((age > 30) ? (double)((int)((age - 30) / 10) * 0.125) : 0); };
    double waist() { return weight / 5.7 + ((age > 28) ? (double)((int)((age - 28) / 2) * 0.1) : 0); };
    bool input_height() {
        cin >> height;
        return true;
    };
    bool input_weight() {
        cin >> weight;
        return true;
    };
    bool input_age() {
        cin >> age;
        return true;
    };

   private:
    double height;
    double weight;
    int age;
};
int main() {
    while (1) {
        info people;
        cout << "please input your height:";
        people.input_height();
        cout << "please input your weight:";
        people.input_weight();
        cout << "please input your age:";
        people.input_age();
        cout << "Hat size = " << people.hat_size() << " in inches." << endl
             << "Jacket size (chest in inches) = " << people.Jacket_size() << " (chest in inches)" << endl
             << "Waist = " << people.waist() << " in inches." << endl;
    }
}