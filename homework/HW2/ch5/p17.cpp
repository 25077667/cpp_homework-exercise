#include <bits/stdc++.h>
using namespace std;
void inputFile() {
    ifstream file;
    file.open("Data.txt");
    int arr[10] = {0};
    string rawData;
    unsigned int len = 0;
    while (file >> rawData) {
        for (int i = 0; (unsigned int)i < rawData.length(); i++) {
            if ((rawData[i] - '0') > 9 || (rawData[i] - '0')<0)
                continue;

            arr[(rawData[i] - '0')]++;
            len++;
        }
    }
    for (int i = 0; i < 10; i++)
        cout << i << "\t" << arr[i] *1.0 / len << endl;
    file.close();
}
int main() {
    cout << "input file" << endl;
    inputFile();
    return 0;
}