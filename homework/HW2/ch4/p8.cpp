#include <bits/stdc++.h>
using namespace std;
void output(int pounds, double ounces) {
    cout << "it is " << pounds << "pounds and " << ounces << " ounces." << endl;
}
void calculating(double kg, double g) {
    //1 pound = 453.59237g
    double weight = kg * 1000 + g;//g
    int pounds = weight / 453.5923;
    output(pounds, (weight - pounds * 453.59237) * 0.0352739619);
}
void input() {
    double kg, g;
    cout << "input kg ";
    cin >> kg;
    cout << "input g ";
    cin >> g;
    calculating(kg, g);
}

int main() {
    char tmp;
    do {
        input();
    } while (cout << "keep? (y/n)" && cin >> tmp && tmp == 'y');
}