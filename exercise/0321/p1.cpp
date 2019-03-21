#include <bits/stdc++.h>
using namespace std;

void swap_val(int a, int b) {
    swap(a, b);
    cout <<"In swap value function is "<< a << " " << b << endl;
}
void swap_ref(int& a, int& b) {
    swap(a, b);
    cout << "In swap reference function is " << a << " " << b << endl;
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << "Your init value is " << a << " " << b << endl
         << endl;
    swap_val(a,b);
    cout << "In main function is " << a << " " << b << endl;
    swap_ref(a,b);
    cout << "In main function is " << a << " " << b << endl;
    return 0;
}