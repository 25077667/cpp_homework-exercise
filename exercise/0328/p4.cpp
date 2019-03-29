#include <bits/stdc++.h>
using namespace std;

int getRandomNumber(int module) {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return (mt_rand() % module);
}

void printMap(char* _map) {
    for (int i = 0; i <= sizeof(_map); i++) {
        if (i % 3 == 0 && i)
            cout << endl;
        cout << _map[i] << " ";
    }
    cout << endl;
}

int result(char* _map) {
    if ((int)_map[0] + (int)_map[1] + (int)_map[2] == 3 * (int)'O' ||
        (int)_map[3] + (int)_map[4] + (int)_map[5] == 3 * (int)'O' ||
        (int)_map[6] + (int)_map[7] + (int)_map[8] == 3 * (int)'O' ||
        (int)_map[0] + (int)_map[3] + (int)_map[6] == 3 * (int)'O' ||
        (int)_map[1] + (int)_map[4] + (int)_map[7] == 3 * (int)'O' ||
        (int)_map[2] + (int)_map[5] + (int)_map[8] == 3 * (int)'O' ||
        (int)_map[0] + (int)_map[4] + (int)_map[8] == 3 * (int)'O' ||
        (int)_map[2] + (int)_map[4] + (int)_map[6] == 3 * (int)'O')
        return 1;  //user win
    else if ((int)_map[0] + (int)_map[1] + (int)_map[2] == 3 * (int)'X' ||
             (int)_map[3] + (int)_map[4] + (int)_map[5] == 3 * (int)'X' ||
             (int)_map[6] + (int)_map[7] + (int)_map[8] == 3 * (int)'X' ||
             (int)_map[0] + (int)_map[3] + (int)_map[6] == 3 * (int)'X' ||
             (int)_map[1] + (int)_map[4] + (int)_map[7] == 3 * (int)'X' ||
             (int)_map[2] + (int)_map[5] + (int)_map[8] == 3 * (int)'X' ||
             (int)_map[0] + (int)_map[4] + (int)_map[8] == 3 * (int)'X' ||
             (int)_map[2] + (int)_map[4] + (int)_map[6] == 3 * (int)'X')
        return 2;  //computer win
    else
        return 0;  //keep gaming
}

int userTurn(char*(&_map), vector<int>& selection) {
    int num;
    cout << "please input the point number you want.";
    cin >> num;
    vector<int>::iterator iter = find(selection.begin(), selection.end(), num);
    if (iter == selection.end()) {
        cout << "input error" << endl;
        return -1;  //should input again
    } else {
        selection.erase(iter);
        _map[num] = 'O';
        return result(_map);
    }
}

int computerTurn(char*(&_map), vector<int>& selection) {
    vector<int>::iterator iter = selection.begin() + getRandomNumber(selection.size()-1);
    int num = *iter;
    selection.erase(iter);
    _map[num] = 'X';
    return result(_map);
}

int main() {
    char* jiugonggeMap = new char[9];
    vector<int> selection;
    for (int i = 0; i <= sizeof(jiugonggeMap); i++) {
        jiugonggeMap[i] = char(i + '0');
        selection.push_back(i);
    }
    selection.push_back(999);
    while (1) {
        printMap(jiugonggeMap);
        int userResult = userTurn(jiugonggeMap, selection);
        if (userResult == -1)
            continue;
        else if (userResult == 1) {
            cout << "you win" << endl;
            break;
        } else if (*selection.begin() == 999) {
            cout << "draw" << endl;
            break;
        }        
        if (computerTurn(jiugonggeMap, selection) == 2) {
            cout << "computer win" << endl;
            break;
        }
    }
    return 0;
}