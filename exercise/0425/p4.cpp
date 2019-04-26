#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int final[11] = {0};
    vector<int> grade;
    int cache;
    while (cin >> cache && cache != -1) 
        grade.push_back(cache);
    for (vector<int>::iterator p = grade.begin(); p != grade.end(); p++) {
        final[(*p / 10)]++;
    }
    for (int i = 0; i < 10; i++)
        cout << final[i] << " grade(s) of [" << i * 10 << "," << (i + 1) * 10 - 1 << "]" << endl;
    if (final[10] != 0)
        cout << final[10] << " grade(s) of 100" << endl;
    return 0;
}