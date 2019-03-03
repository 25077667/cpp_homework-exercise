#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    double x, y, n;
    cout << "input the number \"n\" in a line\n";
    cin >> n;
    x = n / 2;
    for (int i = 0; i < 5; i++) {
        y = n / x;
        x = (x + y) / 2;
    }
    cout << fixed << setprecision(2) << x << endl;
}