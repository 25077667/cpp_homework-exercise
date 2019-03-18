#include <bits/stdc++.h>
using namespace std;
int main() {
    // TA correction this problem
    vector<int> prime;
    prime.push_back(2);
    for (int i = 3; i < 100; i += 2) {
        vector<int>::iterator iter;
        for (iter = prime.begin(); iter != prime.end(); iter++) {
            if (i % (*iter) == 0 && (*iter) > sqrt(i)+1 )
                break;
        }
        if (iter == prime.end())
            prime.push_back(i);
    }
    for (vector<int>::iterator iter = prime.begin(); iter != prime.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    return 0;
}