#include <vector>
#include "pizza.h"
using namespace std;
int main() {  //this is Josephus Problem
    vector<Pizza> v;
    int sum = 0;
    Pizza pizza1("Small", "Hand Tossed", 0, 3);
    v.push_back(pizza1);
    Pizza pizza2("Large", "Pan", 2, 1);
    v.push_back(pizza2);
    cout << "there are " << v.size() << " in the order." << endl;
    for (vector<Pizza>::iterator iter = v.begin(); iter != v.end(); iter++) {
        sum += (*iter).computePrice();
        cout << "The pizza is " << (*iter).getSize() << " " << (*iter).getType() << " with " << (*iter).getPepperoniToppings() << " pepperoni toppings and " << (*iter).getCheeseToppings()<<" cheese toppings" << endl;
    }
    cout << "Total price is $" << sum << endl;
}