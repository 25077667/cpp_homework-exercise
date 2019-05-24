#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<double> s1, s2;
    int selection;
    while (cin >> selection && selection != 3) {
        if (selection == 1) {
            int tmp;
            cin >> tmp;
            s1.push(tmp);
        } else if (selection == 2 && ! s1.empty()) {
            s1.pop();
        } else {
            cout << "Don't do that!" << endl;
            exit(1);
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
            cout << s2.top() << " ";
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        cout << endl;
    }

    return 0;
}