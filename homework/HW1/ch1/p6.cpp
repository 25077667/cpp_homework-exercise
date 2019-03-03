#include <iostream>
using namespace std;
int main() {
    int miles, time;
    cout << "input the \"miles time\" in a line\n";
    cin >> miles >> time;
    cout << 2 + ((miles - 2 < 0) ? 0 : (miles - 2) * 0.5) + ((miles - 6 < 0) ? 0 : (miles - 6) * 0.5) + (0.2) * time << endl;
    return 0;
}