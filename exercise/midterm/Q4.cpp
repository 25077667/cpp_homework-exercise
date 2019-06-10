#include <string>
#include <iostream>
using namespace std;

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

string* allocList(int listSize){
	string* list = new string[listSize];
	return list;
}

class DynamicStringArray{
	public:
		DynamicStringArray();
		~DynamicStringArray();
		DynamicStringArray(const DynamicStringArray&);

		int getSize() const{return this->size;}
		void addEntry(string);
		bool deleteEntry(string);
		string getEntry(int);
		
		DynamicStringArray& operator=(const DynamicStringArray&);
	private:
		string* dynamicArray;
		int size;
		
};

DynamicStringArray::DynamicStringArray(){
	size = 0;
	dynamicArray = NULL;
}

DynamicStringArray::DynamicStringArray(const DynamicStringArray& source){
	this->size = source.getSize();
	this->dynamicArray = allocList(this->size);
	for(int i=0; i< this->size; i++)
		this->dynamicArray[i] = source.dynamicArray[i];
}

void DynamicStringArray::addEntry(string s){
	(this->size)++;
	string* newArray = allocList(this->size);
	for(int i = 0; i< this->size - 1; i++)
		newArray[i] = this->dynamicArray[i];
	newArray[this->size - 1] = s;

	delete[] this->dynamicArray;
	this->dynamicArray = newArray;
}

bool DynamicStringArray::deleteEntry(string s){
	bool isFound = false;
	for(int  i = 0; i < this->size; i++){
		if(this->dynamicArray[i] == s){
			isFound = true;

			(this->size)--;
			string* newArray = allocList(this->size);

			for(int j = 0; j < i; j++)
				newArray[j] = this->dynamicArray[j];
			for(int j = i+1; j <= this->size; j++)
				newArray[j-1] = this->dynamicArray[j];

			delete[] this->dynamicArray;
			this->dynamicArray = newArray;

			break;
		}
	}
	return isFound;
}

string DynamicStringArray::getEntry(int index){
	if(index >= this->size || index < 0)
		return NULL;
	else
		return this->dynamicArray[index];
}

DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& source){
	if(this != &source){
		this->size = source.getSize();
		delete[] this->dynamicArray;

		this->dynamicArray = allocList(this->size);
		for(int i=0; i< this->size; i++)
			this->dynamicArray[i] = source.dynamicArray[i];
	}
	return *this;
}

DynamicStringArray::~DynamicStringArray(){
	delete[] this->dynamicArray;
}

// --------------------------------
// --------- END USER CODE --------
// --------------------------------

// ============================================================
//     main function -- You are not allowed to change here!
// ============================================================
int main()
{
	DynamicStringArray names;

	// List of names
	names.addEntry("Allen");
	names.addEntry("Bob");
	names.addEntry("Ciro");
	names.addEntry("David");
	names.addEntry("Eddie");

	// Output list
	cout << "List of names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  // Add and remove some names
  names.addEntry("Frank");
  cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.deleteEntry("Bob");
  cout << "After removing a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.deleteEntry("Garfield");
  cout << "After removing a name that isn't on the list (Garfield):" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.addEntry("Hamlet");
  cout << "After adding another name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  // Remove all of the names by repeatedly deleting the last one
  while (names.getSize() > 0) {
        names.deleteEntry(names.getEntry(names.getSize() - 1));
  }

  cout << "After removing all of the names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.addEntry("Isaac");
  cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	cout << "Testing copy constructor" << endl;
	DynamicStringArray names2(names);
	// Remove Isaac from names
	names.deleteEntry("Isaac");
  	cout << "Copied names:" << endl;
	for (int i = 0; i < names2.getSize(); i++)
		cout << names2.getEntry(i) << endl;
	cout << endl;

	cout << "Testing assignment" << endl;
	DynamicStringArray names3 = names2;
	// Remove Isaac from names2
	names2.deleteEntry("Isaac");
     	cout << "Copied names:" << endl;
	for (int i = 0; i < names3.getSize(); i++)
		cout << names3.getEntry(i) << endl;
	cout << endl;

	cout << "Enter a character to exit." << endl;
	char wait;
	cin >> wait;
	return 0;
}
