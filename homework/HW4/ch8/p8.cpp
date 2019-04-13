#include <iostream>
using namespace std;
class Temperature {
   public:
    Temperature(){};
    ~Temperature(){};
    void setF(double value);
    friend inline const bool operator==(const Temperature& a, const Temperature& b);
    friend istream& operator>>(istream& input, Temperature& thisTemperature);
    friend ostream& operator<<(ostream& output, const Temperature& thisTemperature);

   private:
    double k, c, f;
    int i;
};
int main() {
    Temperature t1, t2;
    cin >> t1;
    cout << t1 << endl;
    cin >> t2;
    cout << t2 << endl;
    cout << "temperature1 == temperature2 : " << ((t1 == t2) ? "true" : "false") << endl;
    return 0;
}
void Temperature::setF(double value) {
    f = value;
    c = (f - 32) * 5 / 9;  //華氏轉攝氏
    k = c + 273.15;        //攝氏轉克式，此行得到kelvin氏溫標
    //此題請以kelvin氏溫標轉為華氏和攝氏溫標，詳細請看 sample
    c = k - 273.15;
    f = c * 9 / 5 + 32;
    // 早安，這是不是很多此一舉呢？
}
const bool operator==(const Temperature& a, const Temperature& b) {
    return a.k == b.k;
}
istream& operator>>(istream& input, Temperature& thisTemperature) {
    cout << "Please input a temperature in Fahrenheit.";
    input >> thisTemperature.f;
    thisTemperature.setF(thisTemperature.f);
    return input;
}
ostream& operator<<(ostream& output, const Temperature& thisTemperature) {
    output << "In Kelvin: " << thisTemperature.k << endl
           << "In Celisus: " << thisTemperature.c << endl
           << "In Fahrenheit: " << thisTemperature.f << endl;
    return output;
}