#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double x, y, n;
    cout << "input the number \"n\" in a line\n";
    cin >> n;
    x = n / 2;
    for (int i = 0; i < 5; i++)
    {
        y = n / x;
        x = (x + y) / 2;
    }
    cout << fixed << setprecision(2) << x << endl;
}