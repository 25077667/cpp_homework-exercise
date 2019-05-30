#include "newUser.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<NU::NewUser> table;
    while (1) {
        int selection;
        cout << "1. Add a user" << endl
             << "2. find hashed user password" << endl
             << "3. Login" << endl
             << "4. exit" << endl;

        cin >> selection;
        if (selection == 1) {
            string name, rawPasswd;
            cout << "Please input new user name: ";
            cin >> name;
            do {
                cout << "Please input new user password: ";
                cin >> rawPasswd;
            } while (rawPasswd.length() < 5);

            NU::NewUser newUserData;
            newUserData.setUserName(name);
            newUserData.setPasswd(rawPasswd);
            table.push_back(newUserData);
        } else if (selection == 2) {
            string name;
            bool isFound = false;
            cout << "Please input your name: ";
            cin >> name;
            for (vector<NU::NewUser>::iterator iter = table.begin(); iter != table.end(); iter++) {
                if (name == iter->getUserName()) {
                    cout << iter->getHashedPasswd() << endl;
                    isFound = true;
                    break;
                }
            }
            if (!isFound)
                cout << "Not found" << endl;
        } else if (selection == 3) {
            string name, rawPasswd, hashedInputPasswd;
            cout << "Please input new user name: ";
            cin >> name;
            cout << "Please input new user password: ";
            cin >> rawPasswd;

            vector<NU::NewUser>::iterator iter = table.begin();
            for(; iter!= table.end(); iter++)
                if(iter->getUserName() == name)
                    break;
            hash<string> str_hash;

            stringstream ss;
            ss << str_hash(rawPasswd);
            ss >> hashedInputPasswd;
            if (iter == table.end() || hashedInputPasswd != iter->getHashedPasswd())
                cout << "input error!" << endl;
            else {
                cout << "You are logged in!" << endl;
            }

        } else {
            break;
        }
    }
}