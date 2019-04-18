#include <bits/stdc++.h>
using namespace std;
class info {
    string ID, name, gender, department;

   public:
    inline const string getID() { return ID; }
    inline const string getName() { return name; }
    inline const string getGender() { return gender; }
    inline const string getDepartment() { return department; }
    void setID(string s) { ID = s; }
    void setName(string s) { name = s; }
    void setGender(string s) { gender = s; }
    void setDepartment(string s) { department = s; }
};
int main() {
    vector<info> people;
    string s, ex = "exit";
    while (cout << "input exit to exit!\n") {
        cout << "enter your department:";
        cin >> s;
        if (s == ex)
            break;
        info newpeople;
        newpeople.setDepartment(s);
        cout << "enter your ID:";
        cin >> s;
        newpeople.setID(s);
        cout << "enter your Name:";
        cin >> s;
        newpeople.setName(s);
        cout << "enter your gender:";
        cin >> s;
        newpeople.setGender(s);
        people.push_back(newpeople);
    }
    for (vector<info>::iterator iter = people.begin(); iter != people.end(); iter++) {
        cout << "the result is: " << endl
             << iter->getDepartment() << endl
             << iter->getGender() << endl
             << iter->getID() << endl
             << iter->getName() << endl;
    }
    return 0;
}