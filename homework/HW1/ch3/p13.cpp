#include <bits/stdc++.h>
#include <random>
using namespace std;
int get_random_number(int module) {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return mt_rand() % module;
}
int main() {
    int number_set[25];
    for (int i = 0; i < 25; i++)
        number_set[i] = i + 1;
    for (int i = 0; i < get_random_number(5000); i++)
        swap(number_set[get_random_number(25)], number_set[get_random_number(25)]);
    for (int i = 0; i < 4; i++)
        cout << number_set[i] << " ";
    cout << endl;
}