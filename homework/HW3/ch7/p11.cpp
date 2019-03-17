#include "bits/stdc++.h"
using namespace std;
class Player {
    string name;
    int score;

   public:
    Player(string Name, int Score) : name(Name), score(Score) {}
    int getScore() { return score; }
    string getName() { return name; }
};

void addNewPlayer(vector<Player> &playerList) {
    int s;
    string n;
    cout << "Enter player's name: ";
    cin >> n;
    cout << "Enter player's score: ";
    cin >> s;
    Player player1(n, s);
    playerList.push_back(player1);
}
void printAllScore(vector<Player> &playerList) {
    for (vector<Player>::iterator iter = playerList.begin(); iter != playerList.end(); iter++) {
        cout << (*iter).getName() << "\t" << (*iter).getScore() << endl;
    }
}

vector<Player>::iterator searchPlayer(vector<Player> &playerList, string n) {
    vector<Player>::iterator iter;
    for (iter = playerList.begin(); iter != playerList.end(); iter++) {
        if ((*iter).getName() == n)
            break;
    }
    return iter;
}

void searchPlayerScore(vector<Player> &playerList) {
    string n;
    cout << "What player search for?";
    cin >> n;
    vector<Player>::iterator iter = searchPlayer(playerList, n);
    if (iter != playerList.end())
        cout << (*iter).getScore() << endl;
    else
        cout << "Not found" << endl;
}
void removePlayer(vector<Player> &playerList) {
    string n;
    cout << "Remove which player?";
    cin >> n;
    vector<Player>::iterator iter = searchPlayer(playerList, n);
    if (iter != playerList.end())
        playerList.erase(iter);
    else
        cout << "Not found" << endl;
}
int main() {  //why not just use map?
    vector<Player> playerList;
    char option;
    cout << "Enter an option." << endl
         << "a. Add a new player and score" << endl
         << "b. Print all player and score" << endl
         << "c. Search for a player's score" << endl
         << "d. Remove a player" << endl
         << "q. Quit" << endl;
    while (cin >> option && option != 'q') {
        switch (option) {
            case 'a':
                addNewPlayer(playerList);
                break;
            case 'b':
                printAllScore(playerList);
                break;
            case 'c':
                searchPlayerScore(playerList);
                break;
            case 'd':
                removePlayer(playerList);
                break;
            default:
                cout << "input error" << endl;
                break;
        }
    }
    return 0;
}