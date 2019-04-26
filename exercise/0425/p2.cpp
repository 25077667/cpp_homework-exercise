#include <bits/stdc++.h>
using namespace std;
class Record {
   private:
    string name, birthday;

   public:
    static int counter;
    Record(string, string);
    const string getName() { return name; }
    const string getBirthday() { return birthday; }
    int getCounter() { return counter; }
};

Record::Record(string n, string b) : name(n), birthday(b) {
    counter++;
}
int Record::counter = 0;

int main() {
    vector<Record> students;
    string n, b;
    while (cout << "name? " && cin >> n && n != "exit") {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "birthday? ";
        getline(cin, b);
        Record newRecord(n, b);
        students.push_back(newRecord);
    }
    for (vector<Record>::iterator iter = students.begin(); iter != students.end(); iter++)
        cout << iter->getName() << endl
             << iter->getBirthday() << endl;

    cout << "Total " << students.at(0).getCounter() << endl;
    return 0;
}