#include <bits/stdc++.h>
using namespace std;
class Pocket {
    int one, five, ten;

   public:
    void setOne(int value) { one = value; };
    void setFive(int value) { five = value; };
    void setTen(int value) { ten = value; };
    const int getOne() { return one; }
    const int getFive() { return five; }
    const int getTen() { return ten; }
    const int calculate(){ return one+five*5+ten*10;}
};
int main() {
    Pocket coin;
    int tmp;
    cout<< "How many one-dollars?";
    cin >> tmp;
    coin.setOne(tmp);
    cout << "How many five-dollars?";
    cin >> tmp;
    coin.setFive(tmp);
    cout << "How many ten-dollars?";
    cin >> tmp;
    coin.setTen(tmp);
    cout<< "You have "<<coin.calculate()<<" dollars"<<endl;
    return 0;
}