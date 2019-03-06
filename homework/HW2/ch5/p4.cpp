#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    map<char, int> table;
    getline(cin, s);
    table['a'] = table['e'] = table['i'] = table['o'] = table['u'] = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        table[(char)s[i]]++;
    }
    cout << "vowel\tcount" << endl
         << "a\t" << table['a'] << endl
         << "e\t" << table['e'] << endl
         << "i\t" << table['i'] << endl
         << "o\t" << table['o'] << endl
         << "u\t" << table['u'] << endl;
}