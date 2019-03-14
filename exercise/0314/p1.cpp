#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    for(int i=0;i<10;i++){
        cout << char((rand() % 26)+'A');
    }
}