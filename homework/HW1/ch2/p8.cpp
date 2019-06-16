#include <bits/stdc++.h>
using namespace std;
int main() {
    int celsius, fahrenheit = 0;
    for (celsius = 100; celsius != fahrenheit; celsius-- && (fahrenheit = celsius * 9 / 5 + 32))
        ;
    cout << celsius << endl;
    return 0;
}