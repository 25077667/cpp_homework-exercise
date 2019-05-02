#include <bits/stdc++.h>
using namespace std;
class Pair {
    int first, second;

   public:
    Pair() : first(0), second(0){};
    Pair(int v) : first(v), second(0){};
    Pair(int v1, int v2) : first(v1), second(v2){};
    const friend Pair operator+(Pair a, Pair b);
    const friend Pair operator*(Pair a, int c);
    friend ostream& operator<<(ostream& output, const Pair a);
};
int main() {
    Pair allPairs[3];
    int c;
    cout << "Please input 3 pairs" << endl;
    for (int i = 0; i < 3; i++) {
        int tmp, f, s;
        cin >> tmp;
        if (!tmp)
            allPairs[i] = Pair(0, 0);
        else if (tmp == 1) {
            cin >> f;
            allPairs[i] = Pair(f, 0);
        } else {
            cin >> f >> s;
            allPairs[i] = Pair(f, s);
        }
    }
    cout << "please input a const c";
    cin >> c;
    for (int i = 0; i < 3; i++)
        cout << allPairs[i];
    cout << "x+y+z = " << allPairs[0] + allPairs[1] + allPairs[2];
    cout << "z*c = " << allPairs[2] * c;
}
const Pair operator+(Pair a, Pair b) {
    return Pair(a.first + b.first, a.second + b.second);
}
const Pair operator*(Pair a, int c) {
    return Pair(a.first * c, a.second * c);
}
ostream& operator<<(ostream& output, const Pair a) {
    output << "(" << a.first << "," << a.second << ")" << endl;
    return output;
}