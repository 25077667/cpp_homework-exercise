#include <bits/stdc++.h>
using namespace std;
map<string, int> table;
void calculate(int itemCode, int& voucherValue) {
    if(itemCode > voucherValue){
        cout << "Insufficient balance" << endl;
        return;
    }
    voucherValue -= itemCode;
}
int main() {
    int voucherValue;
    table["A"] = 10;
    table["B"] = 20;
    table["C"] = 30;
    table["D"] = 40;
    for (map<string, int>::iterator iter = table.begin(); iter != table.end(); iter++)
        cout << iter->first << " " << iter->second << endl;

    cout << "Please input your voucher.";
    cin >> voucherValue;
    while (voucherValue >= table["A"]) {
        string index;
        cout << "Which item do you want? (input the name)";
        cin >> index;
        calculate(table[index], voucherValue);
        cout << "the price of the item you want to buy " << table[index]<<endl;
        cout << "now, you have voucher " << voucherValue << endl<<endl;
    }
    cout << endl
         << "you bankrupt."<<endl;
}