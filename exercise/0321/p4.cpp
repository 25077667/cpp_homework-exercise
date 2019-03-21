#include <bits/stdc++.h>
using namespace std;

void circle_dia(int d, char choice, int& dia) {
    if (choice == 'r')
        dia = 6 * d;
    else
        dia = 3 * d;
}
void circle_area(int d, char choice, int& area) {
    if (choice == 'r')
        area = 3 * d * d;
    else
        area = 3 * d * d / 4;
}

int main() {
    int d, dia = 9488, area = 9544;
    cout << "input dia";
    cin >> d;
    char choice;
    cin >> choice;
    circle_dia(d, choice, dia);
    circle_area(d, choice, area);
    cout << dia << " " << area << endl;
    return 0;
}