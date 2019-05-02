#include "d.h"
using namespace std;
int main() {
    Date allDate[3];
    int choose[2];
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
    cout << "chose 2 date to compare [0,3)";
    cin >> choose[0] >> choose[1];
    if(allDate[choose[0]] > allDate[choose[1]])
        cout << allDate[choose[0]].getYear() << "/" << allDate[choose[0]].getMonth() << "/" << allDate[choose[0]].getDay() << " > " << allDate[choose[1]].getYear() << "/" << allDate[choose[1]].getMonth() << "/" << allDate[choose[1]].getDay()<<endl;
    else if (allDate[choose[0]] < allDate[choose[1]])
        cout << allDate[choose[0]].getYear() << "/" << allDate[choose[0]].getMonth() << "/" << allDate[choose[0]].getDay() << " < " << allDate[choose[1]].getYear() << "/" << allDate[choose[1]].getMonth() << "/" << allDate[choose[1]].getDay() << endl;
    else
        cout << allDate[choose[0]].getYear() << "/" << allDate[choose[0]].getMonth() << "/" << allDate[choose[0]].getDay() << " = " << allDate[choose[1]].getYear() << "/" << allDate[choose[1]].getMonth() << "/" << allDate[choose[1]].getDay() << endl;
}