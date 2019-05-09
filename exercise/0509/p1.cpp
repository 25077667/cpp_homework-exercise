#include <bits/stdc++.h>
using namespace std;

class Date {
   private:
    int year, month, day;

   public:
    Date(){};
    friend istream& operator>>(istream& input, Date& d) {
        input >> d.year >> d.month >> d.day;
        return input;
    }
    friend ostream& operator<<(ostream& output, Date& d){
        output << d.year << "/" << d.month << "/" << d.day << endl;
        return output;
    }
};
 int main() {
     Date d1;
     cin >> d1;
     cout<< d1;
}