#include "d.h"
using namespace std;
int main() {
    Date allDate[3];
    int choose, value;
    cout << "input 3 dates\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". ";
        int tmp[3];
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        allDate[i].setYear(tmp[0]);
        allDate[i].setMonth(tmp[1]);
        allDate[i].setDay(tmp[2]);
    }
    for (int i = 0; i < 3; i++)
        cout << "date " << i + 1 << "\t" << allDate[i].getYear() << "/" << allDate[i].getMonth() << "/" << allDate[i].getDay() << endl;
    cout << "choose a date to add some days[0,3)" << endl;
    cin >> choose;
    cout << "+ ";
    cin >> value;
    Date newDate = allDate[choose] + value;
    cout << newDate.getYear() << "/" << newDate.getMonth() << "/" << newDate.getDay() << endl;
}