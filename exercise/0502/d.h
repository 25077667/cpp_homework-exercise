#include <bits/stdc++.h>
class Date {
    int year, month, day;

   public:
    Date(){};
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    friend bool operator>(Date d1, Date d2);
    friend bool operator<(Date d1, Date d2);
    friend bool operator==(Date d1, Date d2);
    const friend Date operator+(Date& d1, int value);
    const friend int operator-(Date d1, Date d2);
    void normalizeDate();
    void setYear(int value) { year = value; }
    void setMonth(int value) { month = value; }
    void setDay(int value) { day = value; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
};
void Date::normalizeDate() {
    if (this->month == 2 && this->day > 28) {
        this->month ++;
        this->day -= 28;
        normalizeDate();
    }
    if ((this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) && this->day > 31) {
        this->month ++;
        this->day -= 31;
        normalizeDate();
    }
    if ((this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) && this->day > 30) {
        this->month ++;
        this->day -= 30;
        normalizeDate();
    }
    if (this->month > 12) {
        this->year += this->month / 12;
        this->month %= 12;
        normalizeDate();
    }
}
bool operator>(Date d1, Date d2) {
    return (d1.year > d2.year || (d1.year == d2.year && d1.month > d2.month) || (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day));
}
bool operator<(Date d1, Date d2) {
    return (d1.year < d2.year || (d1.year == d2.year && d1.month < d2.month) || (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day));
}
bool operator==(Date d1, Date d2) {
    return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);
}
const Date operator+(Date& d1, int value) {
    d1.day += value;
    d1.normalizeDate();
    return Date(d1.year, d1.month, d1.day);
}
const int operator-(Date d1, Date d2) {
    struct tm t1 = {0}, t2 = {0};
    t1.tm_mday = d1.day;
    t1.tm_mon = d1.month - 1;
    t1.tm_year = d1.year - 1900;
    t2.tm_mday = d2.day;
    t2.tm_mon = d2.month - 1;
    t2.tm_year = d2.year - 1900;
    return abs(difftime(mktime(&t1), mktime(&t2)) / 60 / 60 / 24);
}