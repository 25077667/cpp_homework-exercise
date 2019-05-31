#include <libgen.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int initSeries[2] = {0, 999};
    string filename;
    cout << "Enter the a file name: ";
    cin >> filename;
    ifstream file(filename.c_str());
    if (file.fail()) {
        cerr << "Error: " << strerror(errno);
        exit(1);
    }

    cout << "Create " << filename << "_out to current folder!" << endl;
    ofstream outputFile((filename + "_out").c_str());
    int pre = 0;
    while (!file.eof() && pre < 2)
        file >> initSeries[pre++];

    if (pre < 2)
        for (int i = 0; i < pre; i++)
            outputFile << initSeries[i] << endl;
    else {
        int distance = initSeries[1] - initSeries[0], nextNum, preverous = initSeries[1];
        outputFile << initSeries[0] << endl
                   << initSeries[1] << endl;
        while(!file.eof()){
            file >> nextNum;
            if (nextNum - preverous != distance)
                break;
            outputFile << nextNum <<endl;
            preverous = nextNum;
        }
    }

    outputFile.close();
    file.close();
    return 0;
}