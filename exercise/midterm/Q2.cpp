#include <iostream>
#include <string>

using namespace std;

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

string* allocList(int listSize){
	string* list = new string[listSize];
	return list;
}

class Subscriber{
	public:
		Subscriber();
		Subscriber(Subscriber&);	//copy
		~Subscriber();

		void setName(string s){this->name = s;}
		void setNumChannels(int n){this->numChannels = n;}
		void setChannelList(string*& s){this->channelList = s;}
		string getName() const{return this->name;}
		int getNumChannels() const{return this->numChannels;}
		

		void InputData();
		void OutputData();
		void ResetChannels();

		Subscriber& operator=(const Subscriber&);
	
	private:
		string name;
		int numChannels;
		string* channelList;
};

Subscriber::Subscriber(){
	this->name = "";
	this->numChannels = 0;
	this->channelList = allocList(this->numChannels);
}

Subscriber::Subscriber(Subscriber& source){
	this->name = source.getName();
	this->numChannels = source.getNumChannels();
	this->channelList = allocList(this->numChannels);
	for(int i = 0; i < this->numChannels; i++)
		this->channelList[i] = source.channelList[i];
}

Subscriber::~Subscriber(){
	delete[] this->channelList;
}

void Subscriber::InputData(){
	cout << "Enter Subscriber Name: ";
	cin >> this->name;
	cout << "Enter Number of channels: ";
	cin >> this->numChannels;

	delete[] this->channelList;
	this->channelList = allocList(this->numChannels);

	for(int i = 0; i< this->numChannels; i++){
		cout << "Channel " << i+1 << " "; 
		while(cin.peek() == '\n')
			cin.ignore();
		getline(cin, this->channelList[i]);
	}
}

void Subscriber::OutputData(){
	cout << "Name: " << this->name << endl;
	cout << "Number of channels: " << this->numChannels << endl;
	for(int i=0; i < this->numChannels; i++)
		cout << "Channel " << i+1 << ":" << this->channelList[i] << endl;
	cout << endl; 
}

void Subscriber::ResetChannels(){
	this->numChannels = 0;
	delete[] this->channelList;
}

Subscriber& Subscriber::operator=(const Subscriber& source){
	if(this != &source){
		this->name = source.getName();
		this->numChannels = source.getNumChannels();
		
		delete[] this->channelList;
		this->channelList = allocList(this->numChannels);

		for(int i = 0; i < this->numChannels; i++)
			this->channelList[i] = source.channelList[i];
	}
	return *this;
}

// --------------------------------
// --------- END USER CODE --------
// --------------------------------



// ============================================================
//     main function -- You are not allowed to change here!
// ============================================================
int main()
{
  // Test our code with two Subscriber classes
  Subscriber s1, s2;
  //Test of default constructor
  cout << "Test of default constructor:" << endl;
  s1.OutputData();

  s1.InputData();		// Input data for Subscriber 1
  cout << "Subscriber 1's data:" << endl;
  s1.OutputData();		// Output data for Subscriber 1

  cout << endl;

  s2 = s1;
  cout << "Subscriber 2's data after assignment from Subscriber 1:" << endl;
  s2.OutputData();		// Should output same data as for Subscriber 1

  s1.ResetChannels();
  cout << "Subscriber 1's data after reset:" << endl;
  s1.OutputData();		// Should have no channels

  cout << "Subscriber 2's data, should still have original channels:" << endl;
  s2.OutputData();		// Should still have original channels

  cout << endl;
  return 0;
}
