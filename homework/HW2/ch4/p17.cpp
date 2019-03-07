#include <bits/stdc++.h>
using namespace std;
map<string, int> table;
void readfile() {
    fstream file;
    file.open("scores.txt", ios::in);
    string name;
    int score;
    while (file >> name >> score) {
        table[name] = score;
    }
    file.close();
}
double cal_avg() {
    int sum=0, counter = 0;
    map<string, int>::iterator iter;
    for (iter = table.begin(); iter != table.end(); iter++) {
        sum += iter->second;
        counter++;
    }
    return sum / counter;
}
int main() {
    readfile();
    string name;
    double average = cal_avg();
    cout << "average is " << average << endl;
    map<string, int>::iterator iter;
    while (cout << "input the name you want " && cin >> name) {
        iter = table.find(name);
        if (iter == table.end()) {
            cout << "Not found." << endl;
            continue;
        }
        cout << iter->first << " :" << iter->second << " is " << ((iter->second > average) ? "higher " : "below ") << "than average." << endl;
    }
}