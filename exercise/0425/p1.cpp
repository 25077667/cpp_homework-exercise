#include <iostream>
using namespace std;

class Date {
   private:
    int year;
    int mon;
    int day;

   public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), mon(m), day(d) {}
    void intput() {
        cout << "data input\n";
        cin >> year >> mon >> day;
    }
    void output() {
        cout << "data output\n";
        cout << year << ' ' << mon << ' ' << day << endl;
    }
    friend bool operator==(const Date &d1, const Date &d2);
};

bool operator==(const Date &d1, const Date &d2) {
    if (d1.year == d2.year && d1.mon == d2.mon && d1.day == d2.day)
        return true;
    else
        return false;
}

int main() {
    Date d1;
    Date d2;
    d1.intput();
    d2.intput();

    d1.output();
    d2.output();

    if (d1 == d2)
        cout << "Comparsion Result : the same \n";
    else
        cout << "Comparison Result : different \n";
    return 0;
}