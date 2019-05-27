#include <iostream>
using namespace std;
class Subscriber {
   public:
    Subscriber(string, int, string*&);
    Subscriber(const Subscriber&);
    ~Subscriber();

    void output();
    void reset();
    Subscriber& operator=(const Subscriber&);

   private:
    string name;
    int numChannels;
    string* channelList;
};

string* receiveUserChannelList(int amounts) {
    string* list = new string[amounts];
    while (amounts--) {
        string channelName;
        while (cin.peek() == '\n')
            cin.ignore();
        getline(cin, channelName);
        list[amounts] = channelName;
    }
    return list;
}

int main() {
    string name;
    int channelAmounts;
    string* list;
    cout << "Please input subscriber name: ";
    cin >> name;
    cout << "Please input amounts of subscribing channels: ";
    cin >> channelAmounts;
    list = receiveUserChannelList(channelAmounts);
    Subscriber A(name, channelAmounts, list);
    
    cout << "Person 1's data" <<endl;
    A.output();

    Subscriber B = A;   //use copy constructor
    B = A;  //use assignment operator
    cout << "Person 2's data after assignment from subscriber 1:" << endl;
    B.output();

    A.reset();
    cout << "Person 1's data after reset:" << endl;
    A.output();

    cout << "Person 2's data should still have original detial" << endl;
    B.output();

    return 0;
}

Subscriber::Subscriber(string subscriberName,
                       int channelAmounts,
                       string*& channels) : name(subscriberName),
                                            numChannels(channelAmounts),
                                            channelList(channels) {
}

Subscriber::Subscriber(const Subscriber& source) {
    this->name = source.name;
    this->numChannels = source.numChannels;
    this->channelList = new string[this->numChannels];
    for (int i = 0; i < this->numChannels; i++)
        this->channelList[i] = source.channelList[i];
}

Subscriber::~Subscriber(){
    delete[] this->channelList;
}

void Subscriber::output() {
    cout << "Name: " << name << endl
         << "Number of channels: " << numChannels << endl;
    for (int i = 0; i < numChannels; i++)
        cout << "\t\tChannel " << i + 1 << ": " << channelList[i] << endl;
}

void Subscriber::reset() {
    numChannels = 0;
    delete[] channelList;
}

Subscriber& Subscriber::operator=(const Subscriber& source) {
    if (this == &source) {
        return *this;
    } else {
        this->name = source.name;
        this->numChannels = source.numChannels;
        delete[] this->channelList;
        this->channelList = new string[this->numChannels];
        for (int i = 0; i < this->numChannels; i++)
            this->channelList[i] = source.channelList[i];
    }
}
