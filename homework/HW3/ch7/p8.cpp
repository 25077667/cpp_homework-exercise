#include "bits/stdc++.h"
using namespace std;
int main() {  //want to use map to realize it, but the problem is asking to use vector
    vector<int> input;
    int tmp;
    cout << "enter each grade and -1 is stop" << endl;
    while (cin >> tmp && tmp != -1)
        input.push_back(tmp);
    vector<int> statistics((*max_element(input.begin(),input.end())+1), 0);
    for (vector<int>::iterator iter = input.begin(); iter != input.end(); iter++)
        statistics[*iter]++;
    cout << endl;
    for (vector<int>::iterator iter = statistics.begin(); iter != statistics.end(); iter++) {
        cout << iter - statistics.begin() << " ";
        for (int i = 0; i < *iter; i++)
            cout << '=';
        cout << endl;
    }
}