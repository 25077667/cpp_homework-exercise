#include <bits/stdc++.h>
using namespace std;
void arrangeAuthorName(string& fullName);

void readfile(vector<string>& source) {
    string rawString;
    ifstream file("list.txt", ifstream::in);
    while (getline(file, rawString)) {
        source.push_back(rawString);
        while (file.peek() == '\n')
            file.ignore(numeric_limits<streamsize>::max(), '\n');  //remove all '\n'
    }
    file.close();
}

void removeNumbering(vector<string>& source) {
    for (vector<string>::iterator iter = source.begin(); iter != source.end(); iter++)
        for (string::iterator i = iter->begin(); i != iter->end(); i++) {
            if (!isalpha(*i))
                iter->erase(i--);
            else
                break;
        }
}

void multiSpace_2_singleSpace(vector<string>& source) {
    for (vector<string>::iterator iter = source.begin(); iter != source.end(); iter++)
        for (string::iterator i = iter->begin(); i != iter->end(); i++)
            if (*i == ' ' && *(i - 1) == ' ')
                iter->erase(i--);
}

void removeExtraMinusSign(vector<string>& source) {
    for (vector<string>::iterator iter = source.begin(); iter != source.end(); iter++) {
        while (iter->back() == '-') {
            iter->pop_back();  // '-' in the end of string might let the next function broken
        }
        string::iterator pos = iter->find('-') + iter->begin();
        for (string::iterator i = pos; i != iter->end(); i++)
            if (*i == '-' && i > pos) {
                iter->erase(pos);
                pos = --i;
            }

        // the d request
        pos = iter->find('-') + iter->begin();
        if (*(pos - 1) != ' ')
            iter->insert(pos, ' ');
        if (*(pos + 1) != ' ')
            iter->insert(pos + 1, ' ');  //behind the '-' also need ' '
    }
}

void exchangeSongAndNames(vector<string>& source) {
    for (vector<string>::iterator iter = source.begin(); iter != source.end(); iter++) {
        size_t pos = iter->find('-');
        string song = iter->substr(0, pos - 1), author = iter->substr(pos + 1, iter->length() - pos);
        arrangeAuthorName(author);
        (*iter) = author + " - " + song;
    }
}

void arrangeAuthorName(string& fullName) {
    if (fullName == " no author listed")
        fullName.erase(0, 1);
    else {
        string::iterator pos;
        for (pos = fullName.end(); *pos != ' '; pos--)
            ;  //find the last word(thst is name)
        string name = fullName.substr(pos - fullName.begin(), fullName.length() - (pos - fullName.begin()));

        //arrange last name and (first initial, or first and second names of the composer)
        if (pos == fullName.begin())
            fullName.erase(0, 1);  //only one word, erase ' '
        else {
            fullName.erase(pos - fullName.begin(), name.length());
            name.erase(0, 1);
            fullName = name + fullName;
        }
    }
}

int main() {
    vector<string> origin;
    readfile(origin);
    removeNumbering(origin);
    multiSpace_2_singleSpace(origin);
    removeExtraMinusSign(origin);
    exchangeSongAndNames(origin);
    sort(origin.begin(), origin.end());  //原來 sort 即可
    for (vector<string>::iterator iter = origin.begin(); iter != origin.end(); iter++) {
        cout << (iter - origin.begin())+1 << ". " << *iter << endl;
    }
    return 0;
}