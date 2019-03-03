#include <bits/stdc++.h>
using namespace std;
void computeCoin(int coinValue, int& number, int& amountLeft) {
    //the origin question ask me to use this
    number = amountLeft / coinValue;
    amountLeft -= number * coinValue;
}
int main() {
    int number, want;
    cout << "Please input the mount you want to change from cents.";
    cin >> want;
    cout << want << " cents can be given as " << endl;
    computeCoin(25, number, want);
    cout << number << " quarter(s) ";
    computeCoin(10, number, want);
    cout << number << " dime(s) ";
    computeCoin(1, number, want);
    cout << number << " penny(pennies)."<<endl;
    return main();
}