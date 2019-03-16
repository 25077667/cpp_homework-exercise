#include <iostream>
class Pizza {
   public:
    Pizza();
    Pizza(std::string, std::string, int, int);
    ~Pizza(){};
    int getPepperoniToppings();
    void setPepperoniToppings(int numPepperoni);
    int getCheeseToppings();
    void setCheeseToppings(int numCheese);
    std::string getSize();
    void setSize(std::string newSize);
    std::string getType();
    void setType(std::string newType);
    void outputDescription();
    int computePrice();

   private:
    int pepperoniToppings, cheeseToppings;
    std::string sizeOfPizza, typeOfPizza;
};
