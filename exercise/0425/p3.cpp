#include <iostream>
#include <vector>
using namespace std;
class date {
   private:
    string d;
    int m;

   public:
    void add() {
        cin >> d >> m;
    }
    void print() {
        cout << d << " " << m << endl;
    }
    string getd() {
        return d;
    }
    int getm() {
        return m;
    }
};

void search(vector<date> &x) {
    vector<date>::iterator p;
    string a;
    cout << "input: ";
    cin >> a;
    for (p = x.begin(); p != x.end(); p++) {
        if (p->getd() == a) {
            cout << p->getm() << endl;
            return;
        }
    }
    cout << "no found" << endl;
}
int main() {
    date cache;
    vector<date> data;
    vector<date>::iterator p;
    bool r = true;
    while (r) {
        int flag;
        cout << "1.add data" << endl;
        cout << "2.print" << endl;
        cout << "3.search" << endl;
        cout << "4.exit" << endl;
        cin >> flag;
        int g;
        switch (flag) {
            case 1:
                cache.add();
                data.push_back(cache);
                break;
            case 2:
                g = 0;
                for (p = data.begin(); p != data.end(); p++) {
                    p->print();
                    g += p->getm();
                }
                cout << "sum = " << g << endl;
                break;
            case 3:
                search(data);
                break;
            case 4:
                r = false;
                break;
            default:
                break;
        }
    }
}