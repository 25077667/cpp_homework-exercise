#include <bits/stdc++.h>
using namespace std;

int main() {
    string filename;
    int tmp;
    cout << "Please input the file name you want to read: ";
    cin >> filename;
    ifstream file(filename.c_str());
    if (file.fail()) {
        cerr << "Error: " << strerror(errno);
        exit(1);
    }

    vector<int> fileTable;
    while (file >> tmp) {
        fileTable.push_back(tmp);
    }

    int medain;
    bool isOdd = fileTable.size() % 2;
    if (isOdd)
        medain = fileTable.at(ceil(fileTable.size() / 2));
    else
        medain = (fileTable.at(fileTable.size() / 2) + fileTable.at(fileTable.size() / 2 + 1)) / 2;

    cout << "The medain value is " << medain << endl;

    double quarter = fileTable.size() / 4.0;
    int quartile[3];
    for (int i = 0; i < 3; i++) {
        int index = fileTable.size() * (i + 1) / 4;
        quartile[i] = fileTable.at(index);
    }
    cout << "Quartile: " << quartile[0] << " " << quartile[1] << " " << quartile[2] << endl;
    return 0;
}