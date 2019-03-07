#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cout << "input score ";
    cin >> a;
    if (a < 60) a = sqrt(a) * 10;

    if (a >= 90)
        cout << "1" << endl;
    else if (a >= 80)
        cout << "2" << endl;
    else if (a >= 60)
        cout << "3" << endl;
    else if (a >= 50)
        cout << "4" << endl;
    else if (a >= 40)
        cout << "5" << endl;
    else
        cout << "error" << endl;
}