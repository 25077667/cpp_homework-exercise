#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int initial_deposit, fixed_amount_withdrawn;
    double interest_rate;
    cout << "input format \"initial_deposit interest_rate fixed_amount_withdrawn\" in a line\n";
    cin >> initial_deposit >> interest_rate >> fixed_amount_withdrawn;
    //int counter = 0;
    if ((initial_deposit - fixed_amount_withdrawn) * interest_rate > fixed_amount_withdrawn)
        cout << "The interest earned every month is greater than the fixed withdrawal amount." << endl;
    else {
        //for (counter = 0; initial_deposit > 0; counter++)
        //    initial_deposit = ((initial_deposit - fixed_amount_withdrawn) * interest_rate) + (initial_deposit - fixed_amount_withdrawn);
        //cout << counter << endl;
        
        //O(1) method
        cout << ceil((log((fixed_amount_withdrawn * (1 + interest_rate)) / (fixed_amount_withdrawn * (1 + interest_rate) - initial_deposit * interest_rate)) / log(interest_rate + 1))) << endl;
    }
    return 0;
}