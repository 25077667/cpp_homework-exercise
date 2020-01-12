#include <bits/stdc++.h>
using namespace std;

void readfile(auto& table) {
    fstream file("scores.txt", ios::in);
    string name;
    int score;
    while (file >> name >> score)
        table[name] = score;
    file.close();
}
double cal_avg(auto& table) {
    int sum = 0, counter = 0;
    for (auto iter : table) {
        sum += iter.second;
        counter++;
    }
    return sum * 1.0 / counter;
}
int main() {
    map<string, int> table;
    readfile(table);
    string name;
    double average = cal_avg(table);
    cout << "average is " << average << endl;
    while (cout << "input the name you want " && cin >> name) {
        auto iter = table.find(name);
        if (iter != table.end())
            cout << iter->first << " :" << iter->second << " is "
                 << ((iter->second > average) ? "higher " : "below ") << "than average." << endl;
        else
            cout << "Not found." << endl;
    }
    return 0;
}