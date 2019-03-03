#include <bits/stdc++.h>
using namespace std;
int estimate(bool gender, int father, int mother) {
    if (gender)
        return mother * 13 / 24 + father / 2;
    else
        return father * 6 / 13 + mother / 2;
}
int conversion(int feet) { return 12 * feet; }
int main() {
    while (1) {
        char iof;
        int father, mother;
        bool gender;
        cout << "male or female? (1 or 0)";
        cin >> gender;
        cout << "please select the measures in inch or feet? (i or f)";
        cin >> iof;
        cout << "your father? (in" << ((iof == 'i') ? "inch):" : "feet):");
        cin >> father;
        cout << "your mother? (in" << ((iof == 'i') ? "inch):" : "feet):");
        cin >> mother;

        cout << ((iof == 'i') ? estimate(gender, father, mother) : (estimate(gender, conversion(father), conversion(mother))) / 12) << ((iof == 'i') ? " inch." : " feet.") << endl;
    }
}