#include <iostream>
using namespace std;

struct Grade {
    int score[5] = {0};
    bool isCompelete = false;
    double min, max, avg;
};

double avg_element(Grade grade) {
    double sum=0;
    for(int i=0;i<5;i++)
        sum+= grade.score[i];
    return sum/5;
}

double min_element(Grade grade) {
    int min = INT16_MAX;
    for(int i=0;i<5;i++)
        if(grade.score[i]<min)
            min = grade.score[i];
    return min;
}
double max_element(Grade grade) {
    int max = INT16_MIN;
    for (int i = 0; i < 5; i++)
        if (grade.score[i] > max)
            max = grade.score[i];
    return max;
}

int main() {
    Grade students;
    cout << "please key in scores";
    students.isCompelete = true;
    for (int i = 0; i < 5; i++) {
        cin >> students.score[i];
        if (students.score[i] <= 0)
            students.isCompelete = false;
    }
    for (int i = 0; i < 5; i++)
        cout << students.score[i] << ",";
    cout << "\nFinish in time " << students.isCompelete << endl;

    students.max = max_element(students);
    students.min = min_element(students);
    students.avg = avg_element(students);
    cout << "max " << students.max << " min " << students.min << " avg " << students.avg << endl;
    return 0;
}