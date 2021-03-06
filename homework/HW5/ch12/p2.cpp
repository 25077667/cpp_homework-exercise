#include <bits/stdc++.h>
#include <libgen.h>
using namespace std;

int main() {
    while (1) {
        string filename;
        cout << "Please input the file name you want to read: ";
        cin >> filename;
        ifstream file(filename.c_str());
        if (file.fail()) {
            cerr << "Error: " << strerror(errno);
            exit(1);
        }

        long double summation = 0, inputNumber, counter = 0;
        while (file >> inputNumber) {
            summation += inputNumber;
            counter++;
        }
        cout << "Average of " << counter << " numbers in " << filename << " is " << summation / counter << endl;
        file.close();
    }
    return 0;
}