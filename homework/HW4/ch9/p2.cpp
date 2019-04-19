#include <bits/stdc++.h>
using namespace std;
void printThis(char a) {
    cout << a;
}
void stringOperation(string s) {
    for (unsigned long int i = 0; i < s.length(); i++) {
        if (isalpha(s.at(i))) {
            char result;
            if (isupper(s.at(i)))
                result = (((s.at(i) + 3) > 'Z') ? ((s.at(i) + 2) - 'Z' + 'A') : (s.at(i) + 3));
            else
                result = (((s.at(i) + 3) > 'z') ? ((s.at(i) + 2) - 'z' + 'a') : (s.at(i) + 3));
            printThis(result);
        } else if (isdigit(s.at(i)))
            printThis((((s.at(i) - '0') + 5) % 10) + '0');
        else if (s.at(i) == ' ')
            continue;
        else
            printThis(' ');
    }
}
bool removeAllNewLine() {
    while (cin.peek() == '\n')
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}
int main() {
    string s;
    cout << "When enter a single -1 in one line this program will end." << endl;
    while (removeAllNewLine() && getline(cin, s)) {
        if (s.length() == 2 && s.at(0) == '-' && s.at(1) == '1')
            break;
        stringOperation(s);
    }
    return 0;
}