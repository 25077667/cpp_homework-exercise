#include <iostream>
#include <string>
#include <vector>
using namespace std;

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------


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
