#include <bits/stdc++.h>
using namespace std;

struct Grade {
    int score[5] = {0};
    bool isCompelete = false;
};

int main() {
    Grade students;
    cout << "init score:";
    for (int i = 0; i < 5; i++)
        cout << students.score[i] << " ";
    cout << endl
         << "Finish intime " << students.isCompelete << endl;
    cout << "please input score";
    students.isCompelete = true;
    for (int i = 0; i < 5; i++) {
        cin >> students.score[i];
        if (students.score[i] <= 0)
            students.isCompelete = false;
    }
    for (int i = 0; i < 5; i++)
        cout << students.score[i] << ",";
    cout <<endl<<students.isCompelete <<endl;

    return 0;
}