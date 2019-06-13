#include <iostream>
using namespace std;

class Pokemon {
   public:
    Pokemon(string theName, double theAtk, double theHP) : name(theName), atk(theAtk), hp(theHP) {}
    string getName() const { return this->name; }
    double getAtk() const { return this->atk; }
    double getHP() const { return this->hp; }
    void minusHP(double val) { this->hp -= val; }
    string getAttributes(){};
    void showDetail() {}

   private:
    string name;
    double atk, hp;
};

class Fire_Pokemon : public Pokemon {
   public:
    Fire_Pokemon(string theName, string theAttributes, double theAtk, double theHP) : Pokemon(theName, theAtk, theHP), attributes(theAttributes) {}
    string getAttributes() { return this->attributes; }
    void showDetail() {
        cout << this->getName() << "\t" << this->getAttributes() << "\t" << this->getHP() << "\t" << this->getAtk() << endl;
    }

   private:
    string attributes;
};
class Water_Pokemon : public Pokemon {
   public:
    Water_Pokemon(string theName, string theAttributes, double theAtk, double theHP) : Pokemon(theName, theAtk, theHP), attributes(theAttributes) {}
    string getAttributes() { return this->attributes; }
    void showDetail() {
        cout << this->getName() << "\t" << this->getAttributes() << "\t" << this->getHP() << "\t" << this->getAtk() << endl;
    }

   private:
    string attributes;
};
class Wood_Pokemon : public Pokemon {
   public:
    Wood_Pokemon(string theName, string theAttributes, double theAtk, double theHP) : Pokemon(theName, theAtk, theHP), attributes(theAttributes) {}
    string getAttributes() { return this->attributes; }
    void showDetail() {
        cout << this->getName() << "\t" << this->getAttributes() << "\t" << this->getHP() << "\t" << this->getAtk() << endl;
    }

   private:
    string attributes;
};

double restrain(string A, string B) {
    if (A == B) {
        return 1;
    } else if ((A == "fire" && B == "wood") ||
               (A == "water" && B == "fire") ||
               (A == "wood" && B == "water")) {
        return 2;
    } else {
        return 0.5;
    }
}

void battle(Pokemon& A, Pokemon& B) {
    while (A.getHP() > 0 || B.getHP() > 0) {
        cout << A.getName() << " atk >> " << B.getName() << endl;
        double damage = A.getAtk() * restrain(A.getAttributes(), B.getAttributes());
        B.minusHP(damage);
        //check B die
        if (B.getHP() <= 0)
            break;

        cout << B.getName() << " atk >> " << A.getName() << endl;
        damage = B.getAtk() * restrain(B.getAttributes(), A.getAttributes());
        A.minusHP(damage);
    }
    cout << ((A.getHP() > 0) ? B.getName() : A.getName()) << " dead!" << endl;
}