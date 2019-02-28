#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int initial_deposit, fixed_amount_withdrawn;
    double interest_rate;
    cout << "input format \"initial_deposit interest_rate fixed_amount_withdrawn\" in a line\n";
    cin >> initial_deposit >> interest_rate >> fixed_amount_withdrawn;
    int counter = 0;
    if ((initial_deposit - fixed_amount_withdrawn) * interest_rate > fixed_amount_withdrawn)
        cout << "The interest earned every month is greater than the fixed withdrawal amount." << endl;
    else
    {
        for (counter = 0; initial_deposit > 0; counter++)
            initial_deposit = ((initial_deposit - fixed_amount_withdrawn) * interest_rate / 100) + (initial_deposit - fixed_amount_withdrawn);
        cout << counter << endl;
        //want to use recurrence equation solution to answer it in O(1), but have bugs.
        //cout << 2 + (log((fixed_amount_withdrawn * (-1)) / (initial_deposit * interest_rate - fixed_amount_withdrawn * (initial_deposit + 1) * (initial_deposit + 1))) / log(interest_rate+1))<<endl;
    }
    return 0;
}