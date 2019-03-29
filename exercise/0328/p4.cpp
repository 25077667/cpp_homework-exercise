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
    if (_map[0] == _map[1] == _map[2] == 'O' ||
        _map[3] == _map[4] == _map[5] == 'O' ||
        _map[6] == _map[7] == _map[8] == 'O' ||
        _map[0] == _map[3] == _map[6] == 'O' ||
        _map[1] == _map[4] == _map[7] == 'O' ||
        _map[2] == _map[5] == _map[8] == 'O' ||
        _map[0] == _map[4] == _map[8] == 'O' ||
        _map[2] == _map[4] == _map[6] == 'O')
        return 1;  //user win
    else if (_map[0] == _map[1] == _map[2] == 'X' ||
             _map[3] == _map[4] == _map[5] == 'X' ||
             _map[6] == _map[7] == _map[8] == 'X' ||
             _map[0] == _map[3] == _map[6] == 'X' ||
             _map[1] == _map[4] == _map[7] == 'X' ||
             _map[2] == _map[5] == _map[8] == 'X' ||
             _map[0] == _map[4] == _map[8] == 'X' ||
             _map[2] == _map[4] == _map[6] == 'X')
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
    vector<int>::iterator iter = selection.begin() + getRandomNumber(selection.size());
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
        //cout<<userResult<<endl;
        if (userResult == -1)
            continue;
        else if (userResult == 1) {
            cout << "you win" << endl;
            break;
        }
        if (computerTurn(jiugonggeMap, selection) == 2) {
            cout << "computer win" << endl;
            break;
        }
    }

    return 0;
}