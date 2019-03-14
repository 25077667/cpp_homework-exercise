#include <bits/stdc++.h>
using namespace std;
int main() {
    int playerA = 0, playerB = 0;
    char A, B, trash;
    do {
        cout << "player 1";
        cin >> A;
        cout << "player 2";
        cin >> B;
        if (A == B) {
            cout << "No winner." << endl;
        } else if ((A == 'P' && B == 'R') || (A == 'R' && B == 'S') || (A == 'S' && B == 'P')) {  //A WIN
            playerA++;
            cout << "player 1 win." << endl;
        }
        else {
            playerB++;
            cout << "player 1 win." << endl;
        }
        cout << "player 1 " << playerA << endl
             << "player 2 " << playerB << endl;
    } while (cout << "continue ? (Yy)" && cin >> trash && (trash == 'y' || trash == 'Y'));

    cout << ((playerA > playerB) ? "player 1 win." : "player 2 win.") << endl;
}