// pizza.h
//
// Interface file for the Pizza class.
#include <iostream>
const int SMALL = 0;
const int MEDIUM = 1;
const int LARGE = 2;

const int DEEPDISH = 0;
const int HANDTOSSED = 1;
const int PAN = 2;

class Pizza {
   public:
    int getPepperoniToppings();
    void setPepperoniToppings(int numPepperoni);
    int getCheeseToppings();
    void setCheeseToppings(int numCheese);
    std::string getSize();
    void setSize(std::string newSize);
    std::string getType();
    void setType(std::string newType);
    void outputDescription();
    void computePrice();

   private:
    int pepperoniToppings, cheeseToppings;
    std::string sizeOfPizza, typeOfPizza;
};

// pizza.cpp
//
// This program implements the Pizza class and creates several
// pizza objects to test it out.
