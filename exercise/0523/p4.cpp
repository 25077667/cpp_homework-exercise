#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<double> q1, q2;
    int selection;
    while (cin >> selection && selection != 3) {
        if (selection == 1) {
            int tmp;
            cin >> tmp;
            q1.push(tmp);
        } else if (selection == 2 && !q1.empty()) {
            q1.pop();
        } else {
            cout << "Don't do that!" << endl;
            exit(1);
        }
        while (!q1.empty()) {
            cout << q1.front() << " ";
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        cout << endl;
    }

    return 0;
}