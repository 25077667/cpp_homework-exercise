#include <iostream>
#include <vector>
using namespace std;
class Television {
   public:
    Television(string, double, string*&);
    Television(const Television&);
    ~Television();

    int getSupportAmount() const ;
    void output();
    void setDisplayType();
    void setDimension();
    void setConnectivitySupport();

    Television& operator=(const Television&);

   private:
    string displayType;
    double dimension;
    string* connectivitySupport = NULL;
};

string* receiveUserConnectivitySupport(int amounts) {
    string* list = new string[amounts + 1];
    list[amounts] = "---The end of connectivity support---";
    cout << "Enter this TV connectivity support types" << endl;
    while (amounts--) {
        string types;
        while (cin.peek() == '\n')
            cin.ignore();
        getline(cin, types);
        list[amounts] = types;
    }
    return list;
}

int main() {
    string displayType;
    double dimension;
    int modes;
    string* connectivitySupport = NULL;

    //setting default
    cout << "Please input TV display Type: ";
    cin >> displayType;
    cout << "Please input TV dimension: ";
    cin >> dimension;
    cout << "Please input amounts of connectivity modes: ";
    cin >> modes;
    connectivitySupport = receiveUserConnectivitySupport(modes);
    Television default_TV(displayType, dimension, connectivitySupport);

    vector<Television> TV_table;

    int amountsofTV, index, upperbound;
    cout << "Enter TV numbers: ";
    cin >> amountsofTV;
    upperbound = amountsofTV;
    while (amountsofTV--) {
        TV_table.push_back(default_TV);
    }
    while (cout << "Enter index of TVs required of costumization(input -1 to end)" << endl && cin >> index && index != -1) {
        if (index >= upperbound || index < 0) {
            cerr << "Don't do that!" << endl;
            exit(1);
        }
        TV_table[index].setDisplayType();
        TV_table[index].setDimension();
        TV_table[index].setConnectivitySupport();
    }

    for (vector<Television>::iterator iter = TV_table.begin(); iter != TV_table.end(); iter++) {
        cout << endl
             << "TV#" << iter - TV_table.begin() << ":" << endl;
        iter->output();
    }

    return 0;
}

Television::Television(string DisplayType,
                       double Dimension,
                       string*& ConnectivitySupport) : displayType(DisplayType),
                                                       dimension(Dimension),
                                                       connectivitySupport(ConnectivitySupport) {
}

Television::Television(const Television& source) {
    this->displayType = source.displayType;
    this->dimension = source.dimension;
    int arraySize = source.getSupportAmount() + 1;  // the index of end is this->getSupportAmount()
    this->connectivitySupport = new string[arraySize];
    for (int i = 0; i < arraySize; i++)
        this->connectivitySupport[i] = source.connectivitySupport[i];
}

Television::~Television() {
    delete[] this->connectivitySupport;
}

int Television::getSupportAmount() const {
    int index = 0;
    while (this->connectivitySupport) {
        if (this->connectivitySupport[index] == "---The end of connectivity support---")
            return index;
        index++;
    }
    return 0;
}

void Television::output() {
    cout << "Display type: " << displayType << endl
         << "Dimension(inches): " << dimension << endl
         << "connectivity support types: " << endl;
    int arraySize = this->getSupportAmount();
    for (int i = arraySize - 1; i >= 0; i--)
        cout << "\t\t " << connectivitySupport[i] << endl;
}

void Television::setDisplayType() {
    cout << "Please input TV display Type: ";
    cin >> this->displayType;
}

void Television::setDimension() {
    cout << "Please input TV dimension: ";
    cin >> this->dimension;
}

void Television::setConnectivitySupport() {
    int modes;
    delete[] this->connectivitySupport;
    cout << "Please input amounts of connectivity modes: ";
    cin >> modes;
    this->connectivitySupport = receiveUserConnectivitySupport(modes);
}

Television& Television::operator=(const Television& source) {
    if (this == &source) {
        return *this;
    } else {
        this->displayType = source.displayType;
        this->dimension = source.dimension;
        delete[] this->connectivitySupport;
        int arraySize = source.getSupportAmount() + 1;
        this->connectivitySupport = new string[arraySize];
        for (int i = 0; i < arraySize; i++)
            this->connectivitySupport[i] = source.connectivitySupport[i];
    }
    return *this;
}
