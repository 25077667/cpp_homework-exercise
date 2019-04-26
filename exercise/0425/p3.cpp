#include <iostream>
#include <vector>
using namespace std;

struct Date {
    int year, month, day;
};

class Accounting {
   private:
    Date date;
    int value;

   public:
    Accounting(Date d, int v) : date(d), value(v) {}
    const Date getDate() { return date; }
    const int getValue() { return value; }
    friend inline const bool operator==(const Date d1, const Date d2);
    friend ostream& operator<<(ostream& output, const Accounting current);
};
inline const bool operator==(const Date d1, const Date d2) {
    return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);
}
ostream& operator<<(ostream& output, const Accounting current) {
    output << current.date.year << "-" << current.date.month << "-" << current.date.day << "\t" << current.value;
    return output;
}
void search(vector<Accounting> listAll, const Date want) {
    vector<Accounting>::iterator iter = listAll.begin();
    bool isfound = false;
    for (; iter != listAll.end(); iter++)
        if (iter->getDate() == want) {
            cout << *iter << endl;
            isfound = true;
        }
    if (!isfound)
        cout << "Not found" << endl;
}
void printAll(vector<Accounting> v) {
    for (vector<Accounting>::iterator iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << endl;
}
int main() {
    vector<Accounting> accountingList;
    int selection;
    string questionSet = "1. add data\n2. printAll\n3. Search for date\n4. exit\n";
    while (cout << questionSet && cin >> selection && selection != 4) {
        if (selection == 1) {
            Date newDate;
            int value;
            cout << "Please input you want to record (eg. yyyy mm dd value)" << endl;
            cin >> newDate.year >> newDate.month >> newDate.day >> value;
            Accounting newRecord(newDate, value);
            accountingList.push_back(newRecord);
        } else if (selection == 2) {
            printAll(accountingList);
        } else if (selection == 3) {
            Date want;
            cout << "Please input the day you want to search (eg. yyyy mm dd)" << endl;
            cin >> want.year >> want.month >> want.day;
            search(accountingList, want);
        } else {
            cout << "select error number" << endl;
        }
    }
    return 0;
}