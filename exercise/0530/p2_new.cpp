#include <cstring>
#include <iostream>
#include <random>
using namespace std;

int getRandom(int range) {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return mt_rand() % range;
}

void printArray(int** arr, int row, int column) {
    for (int i = 0; i < row; i++) {
        cout << "[";
        for (int j = 0; j < column; j++)
            cout << arr[i][j] << "\t";
        cout << "]" << endl;
    }
}

void findMode(int** arr, int row, int column) {
    cout << "Value\trow\tcolumn" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            if (arr[i][j])
                cout << arr[i][j] << "\t" << i << "\t" << j << endl;
    }
}

int main() {
    int** arr;
    int row, column, randomNumbers;
    cout << "Please input row and colume" << endl;
    cin >> row >> column;

    arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[column];
        memset(arr[i], 0, sizeof(int) * column);
    }

    cout << "How many random numbers do you want to generate? ";
    cin >> randomNumbers;
    if (randomNumbers > row * column) {
        cerr << "infinite loop" << endl;
        return(1);
    }
    for (int i = 0; i < randomNumbers; i++) {
        int& place = arr[getRandom(row)][getRandom(column)];
        if (place)
            i--;
        else
            place = getRandom(500);
    }

    printArray(arr, row, column);
    cout << "Row: " << row << " Colume: " << column << " nonzero: " << randomNumbers << endl;

    findMode(arr, row, column);

    return 0;
}