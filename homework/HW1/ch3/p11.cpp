#include <bits/stdc++.h>
using namespace std;
bool dies_effect(int number) {
    return ((number < 2) ? false : true);
}
int get_random_number() {
    random_device rd;
    mt19937_64 mt_rand(rd());
    return (mt_rand() % 6) + 1;
}
int human_turn(int human_total_score) {
    char hor;
    int sum = 0;
    while (cout << "hold or roll? Please input (h or r)" && cin >> hor && hor == 'r') {
        int result = get_random_number();
        if (dies_effect(result)) {
            sum += result;
            cout << "Your total score might be add " << sum << endl;
        } else {
            sum = 0;
            cout << "Your roll result is 1." << endl;
            break;
        }
    }
    return human_total_score + sum;
}
int computer_turn(int computer_total_score) {
    int sum = 0;
    while (sum < 20) {
        int result = get_random_number();
        if (dies_effect(result)) {
            sum += result;
            if (sum + computer_total_score >= 100)
                break;
        } else {
            sum = 0;
            break;
        }
    }
    computer_total_score += sum;
    return computer_total_score;
}
int main() {
    int human_total_score = 0, computer_total_score = 0;
    while (human_total_score < 100 && computer_total_score < 100) {
        cout << "Your current score is " << human_total_score << endl
             << "Computer current score is " << computer_total_score << endl;

        human_total_score = human_turn(human_total_score);
        if (human_total_score >= 100) {
            cout << "You got " << human_total_score << ". You win!" << endl;
            break;
        }

        computer_total_score = computer_turn(computer_total_score);
        if (computer_total_score >= 100) {
            cout << "Computer got " << computer_total_score << ". Computer win!" << endl;
            break;
        }
    }
    return 0;
}