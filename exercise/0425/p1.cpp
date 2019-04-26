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
        cout << "data input ";
        cin >> year >> mon >> day;
    }
    void output() {
        cout << "data output ";
        cout << year << ' ' << mon << ' ' << day << endl;
    }
    friend bool operator==(const Date d1, const Date d2);
};

bool operator==(const Date d1, const Date d2) {
    return (d1.year == d2.year && d1.mon == d2.mon && d1.day == d2.day);
}

int main() {
    Date d1;
    Date d2;
    d1.intput();
    d2.intput();

    d1.output();
    d2.output();
    cout << "Comparsion Result : " << ((d1==d2)?"the same.":"different")<<endl;
    return 0;
}