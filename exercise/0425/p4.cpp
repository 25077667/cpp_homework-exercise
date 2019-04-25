#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int final[11] = {0};
    vector<int> grade;
    vector<int>::iterator p;
    int cache;
    while (true) {
        cin >> cache;
        if (cache == -1)
            break;
        grade.push_back(cache);
    }
    for (p = grade.begin(); p != grade.end(); p++) {
        if (*p >= 0 && *p < 10)
            final[0]++;
        else if (*p >= 10 && *p < 20)
            final[1]++;
        else if (*p >= 20 && *p < 30)
            final[2]++;
        else if (*p >= 30 && *p < 40)
            final[3]++;
        else if (*p >= 40 && *p < 50)
            final[4]++;
        else if (*p >= 50 && *p < 60)
            final[5]++;
        else if (*p >= 60 && *p < 70)
            final[6]++;
        else if (*p >= 70 && *p < 80)
            final[7]++;
        else if (*p >= 80 && *p < 90)
            final[8]++;
        else if (*p >= 90 && *p < 100)
            final[9]++;
        else
            final[10]++;
    }
    for (int i = 0; i < 10; i++)
        cout << final[i] << " grade(s) of [" << i * 10 << "," << (i + 1) * 10 - 1 << "]" << endl;
    if (final[10] != 0)
        cout << final[10] << " grade(s) of 100" << endl;
    return 0;
}