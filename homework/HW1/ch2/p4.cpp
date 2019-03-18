#include <bits/stdc++.h>
using namespace std;
int main() {
    // TA correction this problem
    vector<int> prime;
    prime.push_back(2);
    unsigned int t = time(NULL);
    for (int i = 3; i < INT_MAX; i += 2) {
        vector<int>::iterator iter;
        for (iter = prime.begin(); iter != prime.end(); iter++) {
            if (i % (*iter) == 0 || (*iter) > sqrt(i))
                break;
        }
        if (iter == prime.end())
            prime.push_back(i);
    }
    cout << time(NULL) - t << endl;
    //for (vector<int>::iterator iter = prime.begin(); iter != prime.end(); iter++)
    //    cout << *iter << " ";
    //cout << endl;
    return 0;
}