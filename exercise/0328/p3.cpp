#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
    }
}
void selection(vector<int> &arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        int index = i;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[index])
                index = j;
        }
        int tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;
    }
}

int main() {
    int choice;
    while(cin>>choice){
        vector<int> data;
        int tmp;
        cout<<"enter numbers";
        while (cin >> tmp && tmp != -1)
            data.push_back(tmp);
        if(choice ==1){
            bubble(data,data.size());
        }
        else{
            selection(data, data.size());
        }
        for(vector<int>::iterator iter=data.begin(); iter!= data.end();iter++){
            cout<<*iter<<" ";
        }
        cout<<endl;
    }
    return 0;
}