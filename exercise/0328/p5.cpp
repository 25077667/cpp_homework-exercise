#include <bits/stdc++.h>
using namespace std;
char realMap[7][7];
int get_random_number() {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return (mt_rand() % 5) + 1;
}

int main() {
    memset(realMap, 'X', sizeof(realMap));
    //realMap[0][0] = realMap[0][1] = realMap[0][2] = realMap[0][3] = realMap[0][4] = realMap[0][5] = realMap[1][0] = realMap[2][0] = realMap[3][0] = realMap[4][0] = realMap[5][0] = 'O';
    for (int i = 0; i < 7; i++)
        realMap[i][6] = realMap[6][i] = realMap[0][i] = realMap[i][0] = 'O';
    for (int i = 0; i < 5; i++) {
        int x = get_random_number(), y = get_random_number();
        if (realMap[x][y] == 'X')
            realMap[x][y] = 'O';
        else
            i--;
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++)
            cout << realMap[i][j] << " ";
        cout << endl;
    }

    char stepMap[6][6];
    memset(stepMap, '_', sizeof(stepMap));
    bool choice;
    while (cout << "1. mine 0. exit?" && cin >> choice && choice) {
        int row, column;
        cout << "row ";
        cin >> row;
        cout << "column ";
        cin >> column;
        if (realMap[row][column] == 'O') {
            int num = (realMap[row - 1][column - 1] - 'O') + (realMap[row - 1][column] - 'O') + (realMap[row - 1][column + 1] - 'O') + (realMap[row][column - 1] - 'O') + (realMap[row][column + 1] - 'O') + (realMap[row + 1][column - 1] - 'O') + (realMap[row + 1][column] - 'O') + (realMap[row + 1][column + 1] - 'O');
            stepMap[row][column] = char(num / ('X' - 'O') + '0');
            for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= 5; j++)
                    cout << stepMap[i][j] << " ";
                cout << endl;
            }
        } else {
            cout << "You dead!";
            exit(0);
        }
    }
    cout << "You win!" << endl;
    return 0;
}