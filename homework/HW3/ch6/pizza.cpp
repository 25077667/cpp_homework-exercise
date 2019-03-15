#include "pizza.h"
void Pizza::setPepperoniToppings(int numPepperoni) { pepperoniToppings = numPepperoni; }
inline int Pizza::getPepperoniToppings() { return pepperoniToppings; }
int Pizza::getCheeseToppings() { return cheeseToppings; }
void Pizza::setCheeseToppings(int numCheese) { cheeseToppings = numCheese; }
std::string Pizza::getSize() { return sizeOfPizza; }
void Pizza::setSize(std::string newSize) { sizeOfPizza = newSize; }
std::string Pizza::getType() { return typeOfPizza; }
void Pizza::setType(std::string newType) { typeOfPizza = newType; }
void Pizza::computePrice() {
    int basicPrice;
    if (sizeOfPizza[0] == 'S')
        basicPrice = 10;
    else if (sizeOfPizza[0] == 'M')
        basicPrice = 14;
    else
        basicPrice = 17;
    std::cout << "Price of pizza " << basicPrice + (pepperoniToppings + cheeseToppings) * 2 << std::endl;
}
void Pizza::outputDescription() {
    std::cout << "The pizza is " << getSize() << ", " << getType() << ", with " << getPepperoniToppings() << " pepperoni toppings and " << getCheeseToppings() << " cheese toppings." << std::endl;
}