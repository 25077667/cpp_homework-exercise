#include <bits/stdc++.h>
using namespace std;
void inputFile() {
    ifstream file("Data.txt", ios::in);
    int arr[10] = {0};
    string rawData;
    unsigned int len = 0;
    while (file >> rawData) {
        for (unsigned int i = 0; i < rawData.length(); i++) {
            arr[(rawData[i] - '0')]++;
            len++;
        }
    }
    for (int i = 0; i < 10; i++)
        cout << i << "\t" << arr[i] * 1.0 / len << endl;
    file.close();
}
int main() {
    cout << "input file" << endl;
    inputFile();
    return 0;
}