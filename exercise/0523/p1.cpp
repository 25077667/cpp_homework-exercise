#include <bits/stdc++.h>
using namespace std;
int main() {
    int i1 = 8, i2 = 10;
    int* p1 = &i1;
    int* p2 = &i2;
    cout << i1 << "\t" << p1 << endl
         << i2 << "\t" << p2 << endl
         << endl;
    i1 = i2;
    cout << i1 << "\t" << p1 << endl
         << i2 << "\t" << p2 << endl
         << endl;
    p1 = p2;
    cout << i1 << "\t" << p1 << endl
         << i2 << "\t" << p2 << endl;
    return 0;
}