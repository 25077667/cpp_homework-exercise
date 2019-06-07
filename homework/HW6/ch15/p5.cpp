#include <cmath>
#include <iostream>
#include <random>
using namespace std;

int rand() {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return (mt_rand() % 10000) + 10000;
}

class Player {
   public:
    Player() {
        this->range.first = 0;
        this->range.second = 100;
    }
    virtual int getGuess() = 0;
    pair<int, int> getRange() const {
        return this->range;
    }

   private:
    pair<int, int> range;
};

class Human : public Player {
   public:
    Human() : Player() {}
    virtual int getGuess() {
        int guess;
        cin >> guess;
        return guess;
    }
};
class Computer : public Player {
   public:
    Computer() : Player() {}
    virtual int getGuess() {
        int guess = rand() % 100;
        cout << guess << endl;
        return guess;
    }
};
//this block is copy from the origin quenstion
//------------start--------------
bool checkForWin(int guess, int answer) {
    if (answer == guess) {
        cout << "You're right! You win!" << endl;
        return true;
    } else if (answer < guess)
        cout << "Your guess is too high." << endl;
    else
        cout << "Your guess is too low." << endl;
    return false;
}
void play(Player &player1, Player &player2) {
    int answer = 0, guess = 0;
    answer = rand() % 100;
    bool win = false;
    while (!win) {
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess();
        win = checkForWin(guess, answer);
        if (win) return;
        cout << "Player 2's turn to guess." << endl;
        guess = player2.getGuess();
        win = checkForWin(guess, answer);
    }
}
//-----------end----------------

int main() {
    cout << "Round 1: Human v.s Human" << endl;
    Human h1, h2;
    play(h1, h2);
    cout << endl
         << "Round 2: Human v.s Computer" << endl;
    Human h3;
    Computer c1;
    play(h3, c1);
    cout << endl
         << "Round 3: Computer v.s Computer" << endl;
    Computer c2, c3;
    play(c2, c3);
    return 0;
}