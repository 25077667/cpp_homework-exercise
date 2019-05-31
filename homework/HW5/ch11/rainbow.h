#include <iostream>
#include <algorithm>

namespace rainbow {
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
    void printInt(int value) {
        cout << value;
    }
    void printChar(char c) {
        cout << c;
    }
};

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
    cout << "current ";
    printInt(index);
    cout << "\t";
    printChar(inputChar);
    cout << endl;
    return index;
}
bool RainbowColor::nextColorNum() {
    char colorTable[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'P'};
    int index = getColorByName();
    if (index == 7)
        cout << "next 1\tR" << endl;
    else if (index == 0)
        return 0;
    else {
        cout << "next ";
        printInt(index + 1);
        cout << "\t";
        printChar(colorTable[index]);
        cout << endl;
    }
    return true;
}
}  // namespace rainbow