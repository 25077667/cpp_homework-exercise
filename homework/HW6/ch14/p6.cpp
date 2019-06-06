#include <iostream>
#include <string>
using namespace std;

struct expirationDate {
    int year, month, day;
};

class Payment {
   public:
    Payment() { this->paymentValue = 0; }
    Payment(float value) : paymentValue(value) {}
    float getPaymentValue() const { return this->paymentValue; }
    void getPaymentDetails() {
        cout << "from the payment class payment value is " << this->paymentValue << endl;
    }

   private:
    float paymentValue;
};

class CashPayment : public Payment {
   public:
    CashPayment() : Payment() {}
    CashPayment(float value) : Payment(value) {}
    void getPaymentDetails() {
        cout << "The cash payment amount is " << getPaymentValue() << endl;
    }
};

class CreditCardPayment : public Payment {
   public:
    CreditCardPayment();
    CreditCardPayment(float value,
                      string theOwnerName,
                      expirationDate theDate,
                      string theCardNumber) : Payment(value),
                                              ownerName(theOwnerName),
                                              date(theDate),
                                              cardNumber(theCardNumber) {}
    string getOwnerName() const { return this->ownerName; }
    string getCardNember() const { return this->cardNumber; }
    void getPaymentDetails() {
        cout << "The credit payment amount is " << getPaymentValue() << endl
             << "Credit card owner name is " << getOwnerName() << endl
             << "The expiration date is " << date.year << " " << date.month << " " << date.day << endl
             << "the card number is " << getCardNember() << endl;
    }

   private:
    string ownerName;
    expirationDate date;
    string cardNumber;
};

int main() {
    CashPayment cash1(50.2), cash2(20.45);

    cout << "this is cash 1 " << endl;
    cash1.getPaymentDetails();
    cout << endl;
    cout << "this is cash 2 " << endl;
    cash2.getPaymentDetails();
    cout << endl;

    expirationDate credit_1_Date{.year = 2010, .month = 10, .day = 5},
        credit_2_Date{.year = 2009, .month = 11, .day = 15};

    CreditCardPayment credit1(10.5, "Fred", credit_1_Date, "123456789"), credit2(100, "Barney", credit_2_Date, "987654321");
    cout << "this is credit 1 " << endl;
    credit1.getPaymentDetails();
    cout << endl;
    cout << "this is credit 2 " << endl;
    credit2.getPaymentDetails();
    cout << endl;
    return 0;
}