#include <bits/stdc++.h>
using namespace std;

void str(string s1, string s2) {
    cout << s1 << " " << s2 << " " << endl;
}
void str(string s1, string s2, string s3) {
    cout << s1 << " " << s2 << " " << s3 << endl;
}

int main() {
    int tmp;
    string s1, s2, s3;
    cout << " if input != (2 or 3) will exit";
    cin >> tmp;
    if (tmp == 2) {
        cin >> s1 >> s2;
        str(s1, s2);
    } else if (tmp == 3) {
        cin >> s1 >> s2 >> s3;
        str(s1, s2, s3);
    }
    return 0;
}