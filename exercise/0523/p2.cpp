#include <bits/stdc++.h>
using namespace std;
int main() {
    int row, column;
    cin >> row >> column;
    int classicArray[row][column];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> classicArray[i][j];

    int** DynamicArray = new int*[row];

    for (int i = 0; i < row; i++)
        DynamicArray[i] = new int[column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            DynamicArray[i][j] = classicArray[i][j];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << classicArray[i][j] << "@" << &classicArray[i][j] << '\t';
        cout << endl; 
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << DynamicArray[i][j] << "@" << &DynamicArray[i][j] << '\t';
        cout << endl;
    }
    return 0;
}