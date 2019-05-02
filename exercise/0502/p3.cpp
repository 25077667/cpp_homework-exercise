#include "d.h"
using namespace std;
int main() {
    Date allDate[2];
    cout << "input 2 dates\n";
    for (int i = 0; i < 2; i++) {
        cout << i + 1 << ". ";
        int tmp[3];
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        allDate[i].setYear(tmp[0]);
        allDate[i].setMonth(tmp[1]);
        allDate[i].setDay(tmp[2]);
    }
    cout << allDate[0] - allDate[1] << endl;
}