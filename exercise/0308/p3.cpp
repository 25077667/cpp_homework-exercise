#include <bits/stdc++.h>
using namespace std;
int main() {
    int data[3];
    cout << "input 3 edge ";
    cin >> data[0] >> data[1] >> data[2];
    sort(data, data + 3);
    if (data[0] * data[0] + data[1] * data[1] > data[2] * data[2])
        cout << "Obtuse" << endl;
    else if (data[0] * data[0] + data[1] * data[1] == data[2] * data[2])
        cout << "Right" << endl;
    else
        cout << "Acute" << endl;
}