#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char, int> table;
    table['S'] = 10;
    table['A'] = 9;
    table['B'] = 8;
    table['C'] = 7;
    table['D'] = 6;
    table['E'] = 5;
    table['F'] = 0;
    int subjects;
    double sum=0;
    cout<<"Please input the number of subjects";
    cin>>subjects;
    for(int i=0;i<subjects;i++){
        char tmp;
        cout<<"Please input the "<<i+1<<" subject grade(S A B C D E F):";
        cin>>tmp;
        sum+=table[tmp];
    }
    cout<<sum/subjects<<endl;
    return 0;
}