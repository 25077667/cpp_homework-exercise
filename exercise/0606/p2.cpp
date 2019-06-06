#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int score = 0;
    char A, B, tmp_true[10], tmp_my[10];
    ifstream in_true("trueAnswer"), in_my("myAnswer");

    if (in_true.fail() || in_my.fail())
        exit(1);

    for (int i = 0; !in_true.eof() && !in_my.eof(); i++) {
        in_true >> tmp_true[i];
        in_my >> tmp_my[i];
        if (tmp_true[i] == tmp_my[i])
            score += 10;
    }

    for (int i = 0; i < 10; i++)
        cout << tmp_true[i];
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << tmp_my[i];
    cout << endl;
    cout << score << endl;
    in_my.close();
    in_true.close();

    return 0;
}