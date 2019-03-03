#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int milligrams_of_caffeine;
    cout << "input the \"milligrams_of_caffeine\" in a line\n";
    cin>>milligrams_of_caffeine;
    cout<<10000/milligrams_of_caffeine<<endl;
}