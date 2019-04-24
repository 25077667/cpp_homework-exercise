#include <bits/stdc++.h>
using namespace std;
class Weight {
    double kg, p, o;
    void show() {
        cout << "> In Kilograms " << kg << endl;
        cout << "> In Pounds " << p << endl;
        cout << "> In Ounces " << o << endl
             << endl;
    }

   public:
    void setWeightPounds() {
        p = 110;
        kg = p / 2.21;
        o = p * 16;
        show();
    }
    void setWeightKilograms() {
        kg = 60;
        p = kg * 2.21;
        o = p * 16;
        show();
    }
    void setWeightOunces() {
        o = 1800;
        p = 1800 / 16;
        kg = p / 2.21;
        show();
    }
    double getKG() { return kg; }
    double getP() { return p; }
    double getO() { return o; }
};
int main() {
    Weight w;
    cout << "set Kilograms 60" << endl;
    w.setWeightKilograms();
    cout << "set Pounds 110" << endl;
    w.setWeightPounds();
    cout << "set Ounces 1800" << endl;
    w.setWeightOunces();
    return 0;
}