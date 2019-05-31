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
        
        // read only on the current folder
        // dirname is a linux system call in the libgen.h
        if (dirname(const_cast<char*>(filename.c_str())) != ".") {
            cerr << "permission denied\n";
            exit(1);
        }

        long double summation = 0, inputNumber, counter = 0;
        while (file >> inputNumber) {
            summation += inputNumber;
            counter++;
        }
        cout << "Average of " << counter << " numbers in " << filename << " is " << summation / counter << endl;
    }
    return 0;
}