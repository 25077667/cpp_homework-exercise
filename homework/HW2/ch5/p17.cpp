#include <bits/stdc++.h>
using namespace std;
int get_random_number(int module) {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return (mt_rand() % module);
}
string strGenerator() {
    int len = get_random_number(50);
    string result;
    for (int i = 0; i < len; i++)
        result += char(get_random_number(10) + '0');
    return result;
}
void outputFile() {
    ofstream file;
    file.open("Data.txt");
    int len = get_random_number(500) + 100;
    while (len--) {
        file << strGenerator() << endl;
    }
    file.close();
}
void inputFile() {
    ifstream file;
    file.open("Data.txt");
    int arr[10] = {0};
    string rawData;
    unsigned int len = 0;
    while (file >> rawData) {
        for (int i = 0; (unsigned int)i < rawData.length(); i++) {
            arr[(rawData[i] - '0')]++;
            len++;
        }
    }
    for (int i = 0; i < 10; i++)
        cout << i << "\t" << arr[i] *1.0 / len << endl;
    file.close();
}
int main() {
    cout << "output file" << endl;
    outputFile();
    cout << "input file" << endl;
    inputFile();
    return 0;
}