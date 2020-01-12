#include <bits/stdc++.h>
using namespace std;
void output(int kg, int g) {
    cout << "it is " << kg << "kg and " << g << "g." << endl;
}
void calculating(int pounds, int ounces) {
    int weight = pounds * 453.59237 + ounces * 28.3495231;
    output(weight / 1000, weight % 1000);
}
void input() {
    int pounds, ounces;
    cout << "input pounds ";
    cin >> pounds;
    cout << "input ounces ";
    cin >> ounces;
    calculating(pounds, ounces);
}

int main() {
    char tmp;
    do {
        input();
    } while (cout << "keep? (y/n)" && cin >> tmp && tmp == 'y');
}