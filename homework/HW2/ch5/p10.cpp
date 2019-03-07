#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> table;
    table["Chocolate"] = 20;
    table["Vanilla"] = 15;
    table["Strawberry"] = 15;
    table["Raspberry"] = 20;
    table["Butterscotch"] = 20;
    map<string, int> cart;
    cart["Chocolate"] = 0;
    cart["Vanilla"] = 0;
    cart["Strawberry"] = 0;
    cart["Raspberry"] = 0;
    cart["Butterscotch"] = 0;
    char tmp;
    int i = 0;
    map<string, int>::iterator iter;
    cout << "Code\tFlavor" << endl;
    for (iter = table.begin(); iter != table.end(); iter++)
        cout << ++i << "\t" << (iter->first) << endl;

    do {
        i = 0;
        string name;
        int amount;
        cout << "The product remain in the stock "<<endl;
        for (iter = table.begin(); iter != table.end(); iter++)
            cout << ++i << "\t" << (iter->second) << endl;
        cout << "Choose ypou like! (\'product name\' amount): ";
        cin >> name >> amount;
        iter = table.find(name);
        if (iter == table.end()) {
            cout << "Not found." << endl;
            continue;
        }
        if (iter->second - amount >= 0) {
            iter->second -= amount;
            cart[name] += amount;
        } else {
            cout << "the product is not enought" << endl;
        }

    } while (cout << "keep selecting? (y/n)" && cin >> tmp && tmp == 'y');
    cout<<"your cart"<<endl;
    for (iter = cart.begin(); iter != cart.end(); iter++)
        cout<<iter->first<<"\t"<<iter->second<<endl;
    return 0;
}