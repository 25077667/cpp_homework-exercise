#include <iostream>
using namespace std;
int main() {
    int miles, time;
    cout << "input the \"miles time\" in a line\n";
    cin >> miles >> time;
    if (miles <= 2)
        cout << 2 + time * 0.2 << endl;
    else if (miles <= 8)
        cout << 2 + (miles - 2) * 0.5 + ((miles - 6 > 0) ? (miles - 6) : 0) + time * 0.2 << endl;
    else
        cout << 2 + 3 + (miles - 6) + time * 0.2 << endl;
    return 0;
}