#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Please complete the program here by class definition
                                  and function definitions*/
// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------


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
