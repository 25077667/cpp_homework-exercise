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
    void normalizeDate(Date& d);
    void setYear(int value) { year = value; }
    void setMonth(int value) { month = value; }
    void setDay(int value) { day = value; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
};
void Date::normalizeDate(Date& d) {
    if (d.month == 2 && d.day > 28) {
        d.month ++;
        d.day -= 28;
        normalizeDate(d);
    }
    if ((d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) && d.day > 31) {
        d.month ++;
        d.day -= 31;
        normalizeDate(d);
    }
    if ((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && d.day > 30) {
        d.month ++;
        d.day -= 30;
        normalizeDate(d);
    }
    if (d.month > 12) {
        d.year += d.month / 12;
        d.month %= 12;
        normalizeDate(d);
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
    d1.normalizeDate(d1);
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