#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int tmp, counter = 1, max = -999, max_index = 0;
    ifstream fin("temp");
    while (fin >> tmp) {
        counter++;
        if (tmp > max) {
            max = tmp;
            max_index = counter;
        }
    }
    cout << max_index << "\t" << max << endl;

    return 0;
}