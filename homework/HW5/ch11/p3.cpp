#include "rainbow.h"
using std::cout;
using std::endl;

int main() {
    rainbow::RainbowColor rainbowA(1), rainbowB('R');
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
    while (cout << "testing the rainbow color by name and output rainbow color\n" && rainbowA.getColorByName())
        ;
    while (cout << "testing next rainbow color\n" && rainbowB.nextColorNum())
        ;
}