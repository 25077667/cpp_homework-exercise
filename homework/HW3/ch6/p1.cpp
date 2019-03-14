#include <bits/stdc++.h>
using namespace std;
struct Employee {
    int id;
    double core;
    double performance;
    double ideation;
    double score;
    int point;
} employee[5];

int main() {
    string trash;
    ifstream file;
    file.open("CH6_01_data.txt");
    file >> trash >> trash >> trash >> trash;
    for (int i = 0; i < 5; i++) {
        file >> employee[i].id >> employee[i].core >> employee[i].performance >> employee[i].ideation;
        employee[i].score = employee[i].core * 3 + employee[i].performance * 5 / 3 + employee[i].ideation * 2;
        if (employee[i].score > 79)
            employee[i].point = 1;
        else if (employee[i].score > 59)
            employee[i].point = 2;
        else if (employee[i].score > 49)
            employee[i].point = 3;
        else
            employee[i].point = 4;
    }
    file.close();
    cout << "Num\tTotal\tPoint\n";
    for (int i = 0; i < 5; i++)
        cout << employee[i].id << "\t" << employee[i].score << "\t" << employee[i].point << endl;
    return 0;
}