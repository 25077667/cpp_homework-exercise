#include <bits/stdc++.h>
using namespace std;
int get_random_number() {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return (mt_rand() % 365);
}
int main() {
    int arr[365] = {0};
    for (int i = 2; i < 51; i++) {
        double sum = 0;
        for (int k = 0; k < 5000; k++) {
            for (int j = 0; j < i; j++)
                arr[get_random_number()]++;

            for (int j = 0; j < 365; j++)
                if (arr[j] > 1){
                    sum++;
                    break;
                }
            memset(arr, 0, sizeof(arr));
        }
        cout << i << " " << sum/5000 << endl;
    }
    return 0;
}