#include <bits/stdc++.h>
using namespace std;

class Salary {
   public:
    inline double getPay() { return pay; }
    inline int getTime() { return unitTime; }
    void setDays();
    void setPay();
    void setTime() { unitTime = pay / 140; }

   private:
    int days[7] = {0};
    double unitTime = 0;
    double pay = 0;
};

void Salary::setPay() {
    for (int i = 0; i < 7; i++) {
        if (days[i] <= 8)
            pay += days[i] * 140;
        else if (days[i] <= 10)
            pay += ((days[i] - 8) * 140 * 1.33 + 8 * 140);
        else
            pay += ((days[i] - 10) * 140 * 1.66 + 8 * 140 + 2 * 140 * 1.33);
    }
}

void Salary::setDays() {
    for (int i = 0; i < 7; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> days[i];
    }
}

int main() {
    Salary persion;
    persion.setDays();
    persion.setPay();
    persion.setTime();
    cout << persion.getPay() << " " << persion.getTime() << endl;
    return 0;
}