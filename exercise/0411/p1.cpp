#include <bits/stdc++.h>
using namespace std;
const int STUDENT_NUMBERS = 5;
struct Grade {
    int score[STUDENT_NUMBERS] = {0};
    bool isCompelete = false;
};

int main() {
    Grade students;
    //init for teacher
    cout << "init score:";
    for (int i = 0; i < STUDENT_NUMBERS; i++)
        cout << students.score[i] << " ";
    cout << endl
         << "Finish intime " << students.isCompelete << endl
         << "please input score";

    //start
    students.isCompelete = true;
    for (int i = 0; i < STUDENT_NUMBERS; i++) {
        cin >> students.score[i];
        if (students.score[i] <= 0)
            students.isCompelete = false;
    }

    for (int i = 0; i < STUDENT_NUMBERS; i++)
        cout << students.score[i] << ",";
    cout << endl
         << students.isCompelete << endl;

    return 0;
}