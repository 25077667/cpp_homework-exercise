#include <bits/stdc++.h>
using namespace std;
void output_A(int pounds, double ounces) {
    cout << "it is " << pounds << "pounds and " << ounces << " ounces." << endl;
}
void calculating_A(double kg, double g) {
    //1 pound = 453.59237g
    double weight = kg * 1000 + g;  //g
    int pounds = weight / 453.5923;
    output_A(pounds, (weight - pounds * 453.59237) * 0.0352739619);
}
void output(int kg, int g) {
    cout << "it is " << kg << "kg and " << g << "g." << endl;
}
void calculating(int pounds, int ounces) {
    int weight = pounds * 453.59237 + ounces * 28.3495231;
    output(weight / 1000, weight % 1000);
}
void input() {
    int selection;
    cout << "1. pounds ounces to kg and g" << endl
         << "2. kg g to pounds and ounces" << endl;
    cin >> selection;

    if (selection == 1) {
        int pounds, ounces;
        cout << "input pounds ";
        cin >> pounds;
        cout << "input ounces ";
        cin >> ounces;
        calculating(pounds, ounces);
    } else {
        double kg, g;
        cout << "input kg ";
        cin >> kg;
        cout << "input g ";
        cin >> g;
        calculating_A(kg, g);
    }
}

int main() {
    char tmp;
    do {
        input();
    } while (cout << "keep? (y/n)" && cin >> tmp && tmp == 'y');
}