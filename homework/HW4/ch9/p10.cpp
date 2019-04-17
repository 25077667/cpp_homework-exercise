#include <bits/stdc++.h>
using namespace std;
int getRandom(int defficult) {
    int randomValue = 0, module = 1;
    ifstream urandom("/dev/urandom", ios::in | ios::binary);
    if (urandom) {
        urandom.read(reinterpret_cast<char*>(&randomValue), sizeof(int));  //Read from urandom
        urandom.read(reinterpret_cast<char*>(&module), sizeof(int));
        urandom.close();
        module >>= (20 - defficult);
        return randomValue % module;
    } else {
        cout << "Read /dev/urandom failed, you might not in debian.\n";
        exit(1);
    }
}
void cleanSS(stringstream& ss) {
    ss.str("");
    ss.clear();
}
class Trivia {
    void generateProblemSet(int defficult);
    vector<pair<int, pair<int, string>>> problemSet;
    int userScore = 0;

   public:
    Trivia(int defficult);
    void playGame();

    void setUserScore(int current) { userScore += current; };
    inline int getUserScore() { return userScore; };
};

int main() {
    int defficult;
    cout << "Please input the defficult you want(0~4)";
    cin >> defficult;
    if (defficult > 4 || defficult < 0) {
        cout << "Don't do that";
        exit(1);
    }
    Trivia puzzle(defficult);
    puzzle.playGame();
    cout << "It's end of this game, your total score is " << puzzle.getUserScore() << endl;
    return 0;
}
Trivia::Trivia(int defficult) {
    cout << "Trivia game init\n";
    generateProblemSet(defficult);
}
void Trivia::generateProblemSet(int defficult) {
    int numberOFproblems = abs(getRandom(defficult) % 5)+5;
    for (int i = 0; i < numberOFproblems; i++) {
        int a = getRandom(defficult), b = getRandom(defficult);
        pair<int, pair<int, string>> newProblem;
        stringstream ss;
        cleanSS(ss);
        ss << a;
        ss >> newProblem.second.second;
        cleanSS(ss);
        string tmp;
        ss << b;
        ss >> tmp;
        newProblem.second.second += (" + " + tmp);  //problem string
        cleanSS(ss);
        newProblem.second.first = a + b;                         //answer
        newProblem.first = (log10(abs(a)) + log10(abs(b))) * 2;  //score
        problemSet.push_back(newProblem);
    }
}
void Trivia::playGame() {
    for (vector<pair<int, pair<int, string>>>::iterator iter = problemSet.begin(); iter != problemSet.end(); iter++) {
        cout << "Your current score is " << userScore << endl;
        cout << "Question (" << iter - problemSet.begin() + 1 << "/" << problemSet.end() - problemSet.begin() << "): " << endl
             << (*iter).second.second << " = ";
        int userAnswer;
        cin >> userAnswer;
        if (userAnswer == (*iter).second.first) {
            setUserScore((*iter).first);
            cout << "Good, you are correct!" << endl;
        } else
            cout << "Wrong answer, the answoer is " << (*iter).second.first << endl;
    }
}