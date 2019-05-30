#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main() {
    map<int, int> timeindex;
    map<int, int>::iterator iter;
    srand(time(NULL));
    int row, col, nonzero;
    cout << "row and col:" << endl;
    cin >> row >> col;
    int data[row][col] = {0};
    memset(data, 0, sizeof(int)*row*col);   
    cout << "nonzero: ";
    cin >> nonzero;
    for (int i = 0; i < nonzero; i++) {
        int cache = rand() % (row * col);
        if (timeindex[cache] == 0)
            timeindex[cache]++;
        else
            i--;
    }
    for (iter = timeindex.begin(); iter != timeindex.end(); iter++) {
        int r, c;
        r = iter->first / col;
        c = iter->first % col;
        data[r][c] = rand() % 100;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << data[i][j] << "\t";
        cout << endl;
    }
    for (iter = timeindex.begin(); iter != timeindex.end(); iter++) {
        int r, c;
        r = iter->first / col;
        c = iter->first % col;
        cout << "(" << r << " , " << c << " , " << data[r][c] << " )" << endl;
    }
    return 0;
}