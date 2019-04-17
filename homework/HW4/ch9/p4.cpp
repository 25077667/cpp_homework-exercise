#include <bits/stdc++.h>
using namespace std;
void printHead(string s) {
    s.at(0) = toupper(s.at(0));
    cout << s;
}
void operateString(string s, size_t pos = 0) {
    vector<string> v;
    cout << "Please input the string you want to convert." << endl;
    while (cin.peek() == '\n')
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //the '\n' will still in istream while the next time function calling, debug this '\n' for 30 minutes
    getline(cin, s);
    //transform(s.begin(), s.end(), s.begin(), ::tolower);
    while ((pos = s.find(" ")) != string::npos) {
        v.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    v.push_back(s.substr(0, s.length()));  //input the last word to vector
    for (vector<string>::iterator iter = v.begin(); iter != v.end(); iter++) {
        if (iter == v.begin())
            printHead(((*iter).size() != 4) ? (*iter) : "Love");
        else if (v.at(iter - v.begin() - 1).back() == '.' ||
                 v.at(iter - v.begin() - 1).back() == '!' ||
                 v.at(iter - v.begin() - 1).back() == '?')
            printHead(((*iter).size() != 4) ? (*iter) : "Love");
        else if ((*iter).size() == 5 &&
                 (v.at(iter - v.begin()).back() == '.' ||
                  v.at(iter - v.begin()).back() == '!' ||
                  v.at(iter - v.begin()).back() == '?'))
            cout << "love" << v.at(iter - v.begin()).back();
        else if ((*iter).size() == 4 && !ispunct(v.at(iter - v.begin()).back()))
            cout << "love";  //don't put punct in wht word middle, the question didn't ask to constder it.
        else
            cout << *iter;
        cout << " ";
    }
    cout << endl;
}
int main() {
    char tmp;
    do {
        operateString("");
    } while (cout << "Do you want to keep going? [y/n] " && cin >> tmp && tmp == 'y');
    return 0;
}