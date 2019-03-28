#include <bits/stdc++.h>
using namespace std;
char seats[10][10];

void printSeats() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << seats[i][j] << " ";
        cout << endl;
    }
}

int orderSeat(bool canOrder) {
    int row, column;
    printSeats();
    cout << "you can order seats" << endl
         << "row ";
    cin >> row;
    cout << "column ";
    cin >> column;
    if (row < 0 || column < 0)
        return -1;
    else if (row < 10 && column < 10 && seats[row][column] == '\0') {
        cout << "success" << endl;
        seats[row][column] = 'O';
        return 1;
    } else if (row < 10 && column < 10 && seats[row][column] == 'O') {
        cout << "Booking Error" << endl;
        return 1;
    } else {
        cout << "Booking Error" << endl;
        return 1;
    }
}

int main() {
    memset(seats, '\0', sizeof(seats));
    seats[0][0] = seats[0][1] = seats[1][0] = seats[1][1] = seats[0][8] = seats[0][9] = seats[1][9] = seats[1][8] = seats[8][0] = seats[8][1] = seats[9][0] = seats[9][1] = seats[8][8] = seats[8][9] = seats[9][8] = seats[9][9] = 'X';
    while (orderSeat(1)) {
        char tmp;
        cout << "do you want to keep order?(y/n)";
        cin >> tmp;
        if (tmp != 'y')
            break;
    }
    printSeats();
    return 0;
}