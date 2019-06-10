#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Please complete the program here by class definition
                                  and function definitions*/
// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

class Player{
	public:
		int getScore(){return score;}
		string getName(){return name;}
		void setScore(int s){score = s;}
		void setName(string n){name = n;}
	private:
		int score;
		string name;
};


void addPlayer(int n, vector<Player>& v){
	Player newPlayer;
	int s;
	string name;
	cout << "Pleace enter a Player's name.";
	cin >> name;
	cout << "Pleace enter a Player's score.";
	cin >> s;
	newPlayer.setName(name);
	newPlayer.setScore(s);
	v.push_back(newPlayer);
}
void printPlayer(int n, vector<Player>& v){
	cout << "Player Scores" << endl;
	for(vector<Player>::iterator iter = v.begin(); iter != v.end() ; iter++)
		cout << iter->getName() << "\t" << iter->getScore() << endl;
}
void searchPlayer(int n, vector<Player>& v){
	bool isfound = false;
	string want;
	cout << "Witch player to search for?" <<endl;
	cin >> want;
	for(vector<Player>::iterator iter = v.begin(); iter != v.end() ; iter++){
		if(iter->getName() == want){
			cout << "The score for "<< iter->getName() 
			     << " is " << iter->getScore() <<endl;
			isfound = true;
		}
	}
	if(isfound == false)
		cout << "Not found" <<endl;
}
void removePlayer(int n, vector<Player>& v){
	bool isfound = false;
	string want;
	cout << "Witch player to remove?" <<endl;
	cin >> want;
	for(vector<Player>::iterator iter = v.begin(); iter != v.end() ; iter++){
		if(iter->getName() == want){
			v.erase(iter);
			isfound = true;
		}
	}
	if(isfound == false)
		cout << "Not found" <<endl;
}

// --------------------------------
// --------- END USER CODE --------
// --------------------------------

// You cannot change this part of code

int main()
{
  char option;
  vector<Player> players;
  int numPlayers=0;

  do
  {
   cout << "Enter an option." << endl;
   cout << "a. Add new player and score." << endl;
   cout << "b. Print all players and scores." << endl;
   cout << "c. Search for a player's score." << endl;
   cout << "d. Remove a player." << endl;
   cout << "e. Quit." << endl;

   cin >> option;
   cout << endl;
   if (option == 'a')
     addPlayer(numPlayers, players);
   else if (option == 'b')
     printPlayer(numPlayers, players);
   else if (option == 'c')
     searchPlayer(numPlayers, players);
   else if (option == 'd')
     removePlayer(numPlayers, players);
   cout << endl;
  } while (option != 'e');

  return 0;
}
