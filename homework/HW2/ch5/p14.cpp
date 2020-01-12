#include <bits/stdc++.h>
using namespace std;
int main() {
    int table[4][6] = {
        {3, 1, 5, 2, 1, 5},
        {4, 2, 1, 4, 2, 4},
        {3, 1, 2, 4, 4, 1},
        {5, 1, 4, 2, 4, 2}};
    int user_prefer[6] = {0};
    for (int i = 0; i < 3; i++) {
        cout << "enter a moive to rate (100~105). ";
        int index;
        cin >> index;
        cout << "enter rating for this movie (1~5). ";
        cin >> user_prefer[index - 100];
    }
    int recorder = 0, tmp = 999;
    for (int i = 0; i < 4; i++) {
        int score = 0;
        for (int j = 0; j < 6; j++) {
            if (table[i][j] - user_prefer[j] != table[i][j])
                score += ((table[i][j] - user_prefer[j]) * (table[i][j] - user_prefer[j]));
        }
        if (score < tmp) {
            tmp = score;
            recorder = i;
        }
    }
    cout << "the closest reviewer is number " << recorder << endl
         << "Predictions for movies you have not yet seen:" << endl;
    for (int i = 0; i < 6; i++) {
        if (user_prefer[i] == 0)
            cout << "Movie " << i + 100 << " : Predicted Rating = " << table[recorder][i] << endl;
    }

    return 0;
}