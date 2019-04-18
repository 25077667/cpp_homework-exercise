#include <bits/stdc++.h>
using namespace std;
class Info {
    string ID, name, gender, department;

   public:
    Info(string a, string b, string c, string d) : ID(a), name(b), gender(c), department(d) {}
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
    string a, b, c, d;
    cout << "enter your ID:";
    cin >> a;
    cout << "enter your name:";
    cin >> b;
    cout << "enter your gender:";
    cin >> c;
    cout << "enter your department:";
    cin >> d;
    Info people(a, b, c, d);
    cout << "the result is: " << endl
         << people.getDepartment() << endl
         << people.getGender() << endl
         << people.getID() << endl
         << people.getName() << endl;
    return 0;
}