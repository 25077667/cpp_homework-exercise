#include <bits/stdc++.h>
using namespace std;
int main() {
    int value;
    bool US_mode = true;
    if (cin.peek() == 'T') {
        cin.ignore(numeric_limits<streamsize>::max(), 'D');
        cin >> value;
        cout << value / 30 << endl;
    } else if (cin.peek() == 'U') {
        cin.ignore(numeric_limits<streamsize>::max(), 'D');
        cin >> value;
        cout << value * 30 << endl;
    } else
        cout << "error" << endl;
}