#include <iostream>
#include <string>
#include <vector>
using namespace std;

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

string reverse(string s){
	string result;
	for(string::iterator iter = s.end()-1; iter >= s.begin(); iter--)
		result += *iter;
	return result;
}

class BoxOfProduce{
	public:
		BoxOfProduce(){}
		void addBundle(string);
		string boxContents();	//combine to a long string
		BoxOfProduce& operator+(BoxOfProduce&);
	private:
		vector<string> table;
};

void BoxOfProduce::addBundle(string s){
	this->table.push_back(s);
}

string BoxOfProduce::boxContents(){
	string output = "The Box contains: ";
	for(vector<string>::iterator iter = this->table.begin(); iter != this->table.end() ; iter++){
		output += "(" ;
		string num = "";

		//char to string 
		int tmp = (iter-(this->table.begin()))+1;
		while(tmp){
			switch(tmp%10){
				case 1: num+="1";break;
				case 2: num+="2";break;
				case 3: num+="3";break;
				case 4: num+="4";break;
				case 5: num+="5";break;
				case 6: num+="6";break;
				case 7: num+="7";break;
				case 8: num+="8";break;
				case 9: num+="9";break;
				case 0: num+="0";break;
			}
			tmp /= 10;
		}
		output += reverse(num);
		output += ")" + *iter + " ";
	}
	return output;
}

BoxOfProduce& BoxOfProduce::operator+(BoxOfProduce& b){
	BoxOfProduce* newBox = new BoxOfProduce;
	for(vector<string>::iterator iter = this->table.begin(); iter != this->table.end() ; iter++)
		newBox->table.push_back(*iter);
	for(vector<string>::iterator iter = b.table.begin(); iter != b.table.end() ; iter++)
		newBox->table.push_back(*iter);
	return *newBox;
	
}

// --------------------------------
// --------- END USER CODE --------
// --------------------------------
// ============================================================
//     main function -- You are not allowed to change here!
// ============================================================
int main()
{
	BoxOfProduce b1;
	b1.addBundle("Tomato");
	b1.addBundle("Potato");

	BoxOfProduce b2;
	b2.addBundle("Apple");
	b2.addBundle("Pear");
	b2.addBundle("Kiwi");
	b2.addBundle("Durian");

	BoxOfProduce b3;
	b3 = b1 + b2;

	cout << "box-1 " <<b1.boxContents() << endl;
	cout << "box-2 " <<b2.boxContents() << endl;
	cout << "box-3 " <<b3.boxContents() << endl;

	return 0;
}
