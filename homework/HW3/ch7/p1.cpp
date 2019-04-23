#include "bits/stdc++.h"
using namespace std;

class RainbowColor {
    int color;

   public:
    RainbowColor(int);
    RainbowColor(char);
    void testColor(int);
    void testColor(char);
    int getColorByName();
    bool nextColorNum();
};
int main() {
    RainbowColor rainbowA(1), rainbowB('R');
    cout << "testing constructor RainbowColor(char)" << endl;

    rainbowB.testColor('R');
    rainbowB.testColor('O');
    rainbowB.testColor('Y');
    rainbowB.testColor('G');
    rainbowB.testColor('B');
    rainbowB.testColor('I');
    rainbowB.testColor('P');

    cout << "testing constructor RainbowColor(int)" << endl;
    for (int i = 1; i < 8; i++)
        rainbowA.testColor(i);
    while (cout << "get the rainbow by name and output rainbow color\n" && rainbowA.getColorByName())
        ;
    while (cout << "testing next rainbow color\n" && rainbowB.nextColorNum())
        ;
}

RainbowColor::RainbowColor(int value) {
    color = value;
}
RainbowColor::RainbowColor(char c) {
    int value;
    if (c == 'R')
        value = 1;
    else if (c == 'O')
        value = 2;
    else if (c == 'Y')
        value = 3;
    else if (c == 'G')
        value = 4;
    else if (c == 'B')
        value = 5;
    else if (c == 'I')
        value = 6;
    else
        value = 7;
    color = value;
}
void RainbowColor::testColor(int num) {
    char colorTable[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'P'};
    cout << num << "\t" << colorTable[num - 1] << endl;
}
void RainbowColor::testColor(char c) {
    int value;
    if (c == 'R')
        value = 1;
    else if (c == 'O')
        value = 2;
    else if (c == 'Y')
        value = 3;
    else if (c == 'G')
        value = 4;
    else if (c == 'B')
        value = 5;
    else if (c == 'I')
        value = 6;
    else
        value = 7;
    cout << value << "\t" << c << endl;
}
int RainbowColor::getColorByName() {
    char colorTable[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'P'};
    char inputChar;
    cin >> inputChar;
    char* p = find(colorTable, colorTable + 7, inputChar);
    if (p == colorTable + 7) {
        cout << "Not found!\nending loop" << endl;
        return 0;
    }
    int index = p - colorTable + 1;
    cout << "current " << index << "\t" << inputChar << endl;
    return index;
}
bool RainbowColor::nextColorNum() {
    char colorTable[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'P'};
    int index = getColorByName();
    if (index == 7)
        cout << "next 1\tR" << endl;
    else if (index == 0)
        return 0;
    else
        cout << "next " << index+1 << "\t" << colorTable[index] << endl;
    return true;
}