#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cout << " 0 or - is exit." << endl;
    while(cin.peek() == '\n')
        cin.ignore();
    while (cin.peek() == '0' || cin.peek() == '-')
        exit(0);
    cin >> s;
    for (string::iterator iter = s.end() - 1; iter >= s.begin(); iter--)
        cout << *iter;
    main();
}