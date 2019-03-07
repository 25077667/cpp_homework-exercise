#include <bits/stdc++.h>
using namespace std;
int main() {
    int data[24] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int i = 0; i < 24; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    vector<int> prime;
    prime.push_back(2);
    prime.push_back(3);
    for (int i = 5; i < 1000; i++) {
        bool flag = true;
        for (int j = 0; prime[j] * prime[j] <= i; j++) {
            if (i % prime[j] == 0){
                flag = false;
                break;
            }
        }
        if(flag)
            prime.push_back(i);
    }

    cout << "the mount of prime between 3 1000 " << prime.size() << endl;
    return 0;
}