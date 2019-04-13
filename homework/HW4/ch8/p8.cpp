#include <iostream>
using namespace std;
class Temperature {
   public:
    Temperature(){};
    ~Temperature(){};
    void setF(double value);
    friend inline const bool operator==(const Temperature& a, const Temperature& b);
    friend ostream& operator<<(ostream& output, const Temperature& thisTemperature);

   private:
    double k, c, f;
};
int main() {
    Temperature t1, t2;
    double value1, value2;
    cout << "Please input a temperature1 in Fahrenheit.";
    cin >> value1;
    t1.setF(value1);
    cout << t1 << endl;
    cout << "Please input a temperature2 in Fahrenheit.";
    cin >> value2;
    t2.setF(value2);
    cout << t2 << endl;

    cout << "temperature1 == temperature2 : " << ((t1 == t2) ? "true" : "false") << endl;
    return 0;
}
void Temperature::setF(double value) {
    f = value;
    c = (f - 32) * 5 / 9;
    k = c + 273.15;
}
const bool operator==(const Temperature& a, const Temperature& b) {
    return a.k == b.k;
}
ostream& operator<<(ostream& output, const Temperature& thisTemperature) {
    output << "In Kelvin: " << thisTemperature.k << endl
           << "In Celisus: " << thisTemperature.c << endl
           << "In Fahrenheit: " << thisTemperature.f << endl;
    return output;
}