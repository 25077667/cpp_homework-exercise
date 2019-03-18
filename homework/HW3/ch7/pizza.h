#include <iostream>
class Pizza {
   public:
    Pizza();
    Pizza(std::string size, std::string type, int p, int c);
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
    std::string sizeOfPizza, typeOfPizza;
    int pepperoniToppings, cheeseToppings;
    
};
