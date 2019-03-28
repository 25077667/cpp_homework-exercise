#include <bits/stdc++.h>
using namespace std;
int get_random_number() {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return (mt_rand() % 5) + 1;
}

void initMap(char** realMap, char** stepMap) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            realMap[i][j] = 'X';  //init realMap for 'X'

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            stepMap[i][j] = '_';  //init stepMap for '_'

    for (int i = 0; i < 7; i++)
        realMap[i][6] = realMap[6][i] = realMap[0][i] = realMap[i][0] = 'O';  //init realMap boundry
    for (int i = 0; i < 5; i++) {                                             //reandom set 5 safe place
        int x = get_random_number(), y = get_random_number();
        if (realMap[x][y] == 'X')
            realMap[x][y] = 'O';
        else
            i--;
    }
}

void printMap(char** Map) {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++)
            cout << Map[i][j] << " ";
        cout << endl;
    }
}

int main() {
    char** realMap = new char*[7];  //create maps
    for (int i = 0; i < 7; ++i) realMap[i] = new char[7];
    char** stepMap = new char*[6];
    for (int i = 0; i < 6; ++i) stepMap[i] = new char[6];

    initMap(realMap, stepMap);
    printMap(realMap);

    bool choice;
    int counter = 0;
    while (counter < 5 && cout << "1. mine 0. exit?" && cin >> choice && choice) {
        int row, column;
        cout << "row ";
        cin >> row;
        cout << "column ";
        cin >> column;
        if (realMap[row][column] == 'O') {
            int num = (realMap[row - 1][column - 1] - 'O') + (realMap[row - 1][column] - 'O') + (realMap[row - 1][column + 1] - 'O') + (realMap[row][column - 1] - 'O') + (realMap[row][column + 1] - 'O') + (realMap[row + 1][column - 1] - 'O') + (realMap[row + 1][column] - 'O') + (realMap[row + 1][column + 1] - 'O');
            stepMap[row][column] = char(num / ('X' - 'O') + '0');
            printMap(stepMap);
            counter++;
        } else {
            cout << "You dead!";
            exit(0);
        }
    }
    cout << "You win!" << endl;
    return 0;
}