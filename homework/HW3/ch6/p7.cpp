#include "pizza.h"
//no pizza.h
int main() {
    Pizza pizza1, pizza2;
    pizza1.setType("HANDTOSSED");
    pizza1.setSize("Small");
    pizza1.setPepperoniToppings(0);
    pizza1.setCheeseToppings(3);
    pizza1.outputDescription();
    pizza1.computePrice();

    pizza2.setType("PAN");
    pizza2.setSize("Large");
    pizza2.setPepperoniToppings(2);
    pizza2.setCheeseToppings(1);
    pizza2.outputDescription();
    pizza2.computePrice();
}