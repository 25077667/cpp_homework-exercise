#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int miles, time;
    cin>>miles>>time;
    cout << 2 + ((miles - 2 < 0) ? 0 : (miles - 2) * 0.5) + ((miles - 6 < 0) ? 0 : (miles - 6)*0.5)+ (0.2)*time<<endl;
    return 0;
}