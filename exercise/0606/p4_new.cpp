#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void push(vector<int>& v, ifstream& inFile) {
    int tmp;
    while (!inFile.eof()) {
        inFile >> tmp;
        v.push_back(tmp);
    }
}

int main() {
    vector<int> in1, in2;
    ifstream inFile1("seq1"), inFile2("seq2");
    ofstream outFile("merge");

    if (inFile1.fail() || inFile2.fail())
        exit(1);

    push(in1, inFile1);
    push(in2, inFile2);
    vector<int> out(in1.size() + in2.size());

    merge(in1.begin(), in1.end(), in2.begin(), in2.end(), out.begin());

    for (vector<int>::iterator iter = out.begin(); iter != out.end(); iter++)
        outFile << *iter << endl;
    inFile1.close();
    inFile2.close();
    outFile.close();
    return 0;
}
