#include <bits/stdc++.h>
using namespace std;
void output(int pounds, double ounces) {
<<<<<<< HEAD
    cout << "it is " << pounds << " pounds and " << ounces << " ounces." << endl;
}
void calculating(double kg, double g) {
    //2.2046 pound = 1 kg = 1000g
    double weight = kg * 1000 + g;  //g
    int pounds = (weight / 1000) * 2.2046;
    output(pounds, (weight - pounds / 2.2046 * 1000) / 1000 * 2.2046 * 16);
=======
    cout << "it is " << pounds << "pounds and " << ounces << " ounces." << endl;
}
void calculating(double kg, double g) {
    //1 pound = 453.59237g
    double weight = kg * 1000 + g;//g
    int pounds = weight / 453.59237;
    output(pounds, (weight - pounds * 453.59237) * 0.0352739619);
>>>>>>> d92da8f847b089888a8cdd1f4853d09fe2a92a66
}
void input() {
    double kg, g;
    cout << "input kg ";
    cin >> kg;
    cout << "input g ";
    cin >> g;
    calculating(kg, g);
<<<<<<< HEAD
    //cout<<kg<<" "<<g<<endl;
=======
>>>>>>> d92da8f847b089888a8cdd1f4853d09fe2a92a66
}

int main() {
    char tmp;
    do {
        input();
    } while (cout << "keep? (y/n)" && cin >> tmp && tmp == 'y');
}