#include <iostream>
#include <string>

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
