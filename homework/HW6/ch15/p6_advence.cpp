#include <cmath>
#include <iostream>
#include <random>
using namespace std;

int rand() {
    random_device rd;
    mt19937_64 mt_rand(rd());
    default_random_engine generator = default_random_engine(mt_rand());
    normal_distribution<double> distribution(50, 23);
    return distribution(generator);
}

class Player {
   public:
    Player() {}
    virtual int getGuess(pair<int, int>) = 0;

   private:
};

class Human : public Player {
   public:
    Human() {}
    virtual int getGuess(pair<int, int> range) {
        int guess;
        cin >> guess;
        return guess;
    }
};
class Computer : public Player {
   public:
    Computer() {}
    virtual int getGuess(pair<int, int> range) {
        int add = range.first + range.second, guess = 0;
        if (add > 100)
            guess = range.first + 1;
        else if (add < 100)
            guess = range.second - 1;
        else
            guess = add / 2;
        cout << guess << endl;
        return guess;
    }
};

pair<int, int>& modifyRange(pair<int, int>& range, int guess, int result) {
    if (result > 0)
        range.second = guess;
    else
        range.first = guess;
    return range;
}

int checkForWin(int guess, int answer) {
    if (answer == guess) {
        cout << "You're right! You win!" << endl;
        return 0;
    } else if (answer < guess) {
        cout << "Your guess is too high." << endl;
        return 1;
    } else {
        cout << "Your guess is too low." << endl;
        return -1;
    }
}

void play(Player& player1, Player& player2) {
    int answer = 0, guess = 0;
    answer = rand() % 100;
    int result = 1;
    pair<int, int> range(0, 100);
    while (1) {
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess(range);
        result = checkForWin(guess, answer);
        if (!result)
            return;
        range = modifyRange(range, guess, result);

        cout << "Player 2's turn to guess." << endl;
        guess = player2.getGuess(range);
        result = checkForWin(guess, answer);
        if (!result)
            return;
        range = modifyRange(range, guess, result);
    }
}

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