#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char* s = new char[81];
    int counter = 1;
    cout << "Enter a string less then 80 char." << endl;
    cin.getline(s, 80);
    char *head = s-1, *tail = s + strlen(s);
    for (; head < tail;) {
        counter += (isspace(*tail) ? 1 : 0) + (isspace(*head) ? 1 : 0);
        swap(*head, *tail);
        head++;
        tail--;
    }
    cout << "Reversed string is " << s << endl
         << "And your number of word is " << counter << endl;

    return 0;
}