#include "bits/stdc++.h"
using namespace std;

class RainbowColor {
    map<char, int> table;
   public:
    RainbowColor();
    void testColor(int);
    void testColor(char);
    bool getColorByName();
    bool nextColorNum();
};
int main() {
    RainbowColor rainbow;
    cout << "testing constructor RainbowColor(char)" << endl;
    rainbow.testColor('R');
    rainbow.testColor('O');
    rainbow.testColor('Y');
    rainbow.testColor('G');
    rainbow.testColor('B');
    rainbow.testColor('I');
    rainbow.testColor('P');

    cout << "testing constructor RainbowColor(int)" << endl;
    for (int i = 1; i < 8; i++)
        rainbow.testColor(i);
    while (cout << "get the rainbow by name and output rainbow color\n" && rainbow.getColorByName()) {};
    while (cout << "testing next rainbow color\n" && rainbow.nextColorNum()) {};
}
RainbowColor::RainbowColor() {
    table['R'] = 1;
    table['O'] = 2;
    table['Y'] = 3;
    table['G'] = 4;
    table['B'] = 5;
    table['I'] = 6;
    table['P'] = 7;
}
void RainbowColor::testColor(int num) {
    map<char, int>::iterator iter;
    for (iter = table.begin(); iter->second != num; iter++);
    cout << iter->first << "\t" << iter->second << endl;
}
void RainbowColor::testColor(char c) {
    cout << c << "\t" << table[c] << endl;
}
bool RainbowColor::getColorByName() {
    char c;
    cin >> c;
    map<char, int>::iterator iter;
    iter = RainbowColor::table.find(c);
    if (iter != table.end()) {
        cout << iter->second << "\t" << iter->first << endl;
        return true;
    } else {
        cout << "Not found" << endl;
        return false;
    }
}
bool RainbowColor::nextColorNum() {
    char c;
    cin >> c;
    map<char, int>::iterator iter;
    iter = table.find(c);
    if (iter != table.end()) {
        cout << "current " << iter->first << "\t" << iter->second << endl;
        for (iter = table.begin(); iter->second != table[c]+1 && iter!=table.end(); iter++);

        if (iter->second)
            cout << "next " << iter->first << "\t" << iter->second << endl;
        else
            cout << "next " << "R\t1" << endl;

        return true;
    } else {
        cout << "Not Found" << endl;
        return false;
    }
}