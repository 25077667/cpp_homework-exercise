#include <iostream>
using namespace std;

int main() {
    string* list = new string[5];
    int listSize = 5;
    int selection;
    list[0] = "Frink";
    list[1] = "Wiggun";
    list[2] = "Allen";
    list[3] = "Quimby";
    list[4] = "Flanders";

    for (int i = 0; i < listSize; i++)
        cout << i << "\t" << list[i] << endl;

    while (cout << "Please add, erase or exit!(add: 1, erase: 2, exit: 0)" && cin >> selection) {
        cout << "In the list" << endl;

        if (selection == 1) {
            string newName;
            cout << "Enter a name you want to add: ";
            string* newList = new string[++listSize];
            for (int i = 0; i < listSize - 1; i++)
                newList[i] = list[i];
            cin >> newList[listSize - 1];

            delete[] list;
            list = newList;
        } else if (selection == 2) {
            string want;
            bool isFound = false;

            cout << "Enter a name you want to erase: ";
            cin >> want;

            for (int i = 0; i < listSize; i++)
                if (list[i] == want) {
                    isFound = true;
                    for (int j = i + 1; j < listSize; j++)
                        list[j - 1] = list[j];
                    //delete list[--listSize];
                    listSize --;
                    break;
                }
            if (!isFound)
                cout << "Not found!" << endl;
        } else {
            break;
        }
        for (int i = 0; i < listSize; i++)
            cout << i << "\t" << list[i] << endl;
    }
    return 0;
}