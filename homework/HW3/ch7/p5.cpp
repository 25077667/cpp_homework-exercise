#include "bits/stdc++.h"
using namespace std;
int main() {
    vector<int> v;
    int num, counter = 0;
    cout << "How many people of suitors?";
    cin >> num;
    for (int i = 0; i < num; i++)
        v.push_back(i + 1);

    for (int i = 1; i < num; i++) {
        counter = (counter + 2) % v.size();
        v.erase(v.begin() + counter);
    }
    cout << "you should stand at " << *v.begin() << endl;
}