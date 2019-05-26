#include <bits/stdc++.h>
using namespace std;
class Money {
   public:
    Money();
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    double getAmount() const;
    int getDollars() const;
    int getCents() const;
    friend const Money operator+(const Money& amount1, const Money& amount2);
    friend const Money operator-(const Money& amount1, const Money& amount2);
    friend bool operator==(const Money& amount1, const Money& amount2);
    friend bool operator>=(const Money& amount1, const Money& amount2);
    friend bool operator<=(const Money& amount1, const Money& amount2);
    friend bool operator>(const Money& amount1, const Money& amount2);
    friend bool operator<(const Money& amount1, const Money& amount2);
    friend const Money operator-(const Money& amount);  //let it become negative
    const Money percents(int percentFigure) const;
    friend ostream& operator<<(ostream& output, const Money& amount);
    friend istream& operator>>(istream& input, Money& amount);

   private:
    int dollars, cents;
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
};
int main() {
    Money yourMoney, myMoney(10, 9);
    int percent;
    cout << "Enter an amount of money: ";
    cin >> yourMoney;
    cout << "Enter a percent you wish to take of your amount: ";
    cin >> percent;
    cout << "Your amount is " << yourMoney << endl
         << "My amonut is " << myMoney << endl
         << percent << "% of your amount is " << yourMoney.percents(percent) << endl
         << "15% of my amount is " << myMoney.percents(15) << endl;

    if (yourMoney == myMoney)
        cout << "You are as rich as me." << endl;
    else
        cout << "One of us is richer" << endl;
    cout << yourMoney << " + " << myMoney << " equals " << yourMoney + myMoney << endl
         << yourMoney << " - " << myMoney << " equals " << yourMoney - myMoney << endl;

    cout << "Your amount is " << yourMoney << endl
         << "My amonut is " << myMoney << endl;
    cout << "Your amount is " << ((yourMoney >= myMoney) ? "" : "not ") << "greater or equal than my amount." << endl
         << "The sum of our amount is " << ((yourMoney + myMoney > yourMoney - myMoney) ? "" : "not ") << "greater than the difference." << endl;
    cout << "Your amount is " << ((yourMoney <= myMoney) ? "" : "not ") << "less or equal than my amount." << endl
         << "The sum of our amount is " << ((yourMoney + myMoney < yourMoney - myMoney) ? "" : "not ") << "less than the difference." << endl;
    return 0;
}
int Money::dollarsPart(double amount) const {
    return (int)amount;
}
int Money::centsPart(double amount) const {
    double allCent = amount * 100;
    int intCents = round(fabs(allCent)) % 100;
    if (amount < 0)
        intCents = -intCents;
    return intCents;
}
int Money::round(double number) const {
    return int(floor(number + 0.5));
}
Money::Money() {
    dollars = cents = 0;
}
Money::Money(double amount) {
    dollars = dollarsPart(amount);
    cents = centsPart(amount);
}
Money::Money(int theDollars, int theCents) {
    dollars = theDollars;
    cents = theCents;
}
Money::Money(int theDollars) {
    dollars = theDollars;
    cents = 0;
}
double Money::getAmount() const {
    return dollars + cents * 0.01;
}
int Money::getDollars() const {
    return dollars;
}
int Money::getCents() const {
    return cents;
}
const Money operator-(const Money& amount) {
    return Money(amount.dollars * -1, amount.cents * -1);
}
const Money operator+(const Money& amount1, const Money& amount2) {
    double allCent1 = amount1.dollars * 100 + amount1.cents;
    double allCent2 = amount2.dollars * 100 + amount2.cents;
    int sumDollars = allCent1 + allCent2;
    int finalDallars = abs(sumDollars) / 100, finalCents = abs(sumDollars) % 100;
    if (sumDollars < 0) {
        finalDallars = -finalDallars;
        finalCents = -finalCents;
    }
    return Money(finalDallars, finalCents);
}
const Money operator-(const Money& amount1, const Money& amount2) {
    double allCent1 = amount1.dollars * 100 + amount1.cents;
    double allCent2 = amount2.dollars * 100 + amount2.cents;
    int sumDollars = allCent1 - allCent2;
    int finalDallars = abs(sumDollars) / 100, finalCents = abs(sumDollars) % 100;
    if (sumDollars < 0) {
        finalDallars = -finalDallars;
        finalCents = -finalCents;
    }
    return Money(finalDallars, finalCents);
}
bool operator==(const Money& amount1, const Money& amount2) {
    return (amount1.dollars == amount2.dollars && amount1.cents == amount2.cents);
}
bool operator>=(const Money& amount1, const Money& amount2) {
    return (amount1.dollars * 100 + amount1.cents >= amount2.dollars * 100 + amount2.cents);
}
bool operator<=(const Money& amount1, const Money& amount2) {
    return (amount1.dollars * 100 + amount1.cents <= amount2.dollars * 100 + amount2.cents);
}
bool operator>(const Money& amount1, const Money& amount2) {
    return (amount1.dollars * 100 + amount1.cents > amount2.dollars * 100 + amount2.cents);
}
bool operator<(const Money& amount1, const Money& amount2) {
    return (amount1.dollars * 100 + amount1.cents < amount2.dollars * 100 + amount2.cents);
}
const Money Money::percents(int percentFigure) const {
    int allCent = dollars * 100 + cents;
    allCent *= percentFigure / 100;
    return Money(allCent / 100, allCent % 100);
}
ostream& operator<<(ostream& output, const Money& amount) {
    output << '$' << ((amount.dollars < 0 || amount.cents < 0) ? "-" :"") << abs(amount.dollars) << "." << ((abs(amount.cents) < 10) ? "0" :"") << abs(amount.cents);
    return output;
}
istream& operator>>(istream& input, Money& amount) {
    char dollarSign;
    input >> dollarSign;
    if (dollarSign != '$') {
        cout << "No dollar sign in Money input.\n";
        exit(1);
    }
    double in;
    input >> in;
    amount = Money(in);
    return input;
}