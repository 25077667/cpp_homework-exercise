#include <bits/stdc++.h>
using namespace std;
class Array {
   public:
    Array();
    Array(int sz);
    Array(int length, char elemant);
    ~Array();
    inline const int getSize();
    void setSize(const int sz);
    void setElement(char element);
    void clear();
    char& operator[](const int place);
    friend ostream& operator<<(ostream& output, const Array& thisArray);
    friend istream& operator>>(istream& input, Array& thisArray);

   private:
    int size;
    char data[100];
};
int main() {
    Array newArray(10);
    cout << "Default output (10):" << newArray;
    newArray.clear();
    while (1) {
        cout << "First sz member of the char array to";
        cin >> newArray;
        cout << newArray;
        newArray.clear();
    }
    return 0;
}
Array::Array() {
    memset(data, '\0', 100);
}
Array::Array(int sz) {
    size = sz;
    memset(data, '#', sz);
}
Array::Array(int sz, char elements) {
    size = sz;
    memset(data, '\0', 100);
    memset(data, elements, sz);
}
Array::~Array() {}
inline const int Array::getSize() {
    return size;
}
void Array::setSize(const int sz) {
    size = sz;
}
void Array::setElement(char element) {
    memset(data, element, size);
}
void Array::clear() {
    memset(data, '\0', 100);
    size = 0;
    cout << "-----clear array-----" << endl;
}
char& Array::operator[](const int place) {
    if (place < 0 || place >= size) {
        cout << "index error" << endl;
        exit(1);
    }
    return data[place];
}
ostream& operator<<(ostream& output, const Array& thisArray) {
    for (int i = 0; i < thisArray.size; i++)
        output << thisArray.data[i];
    output << endl
           << "Size: " << thisArray.size << endl;
    return output;
}
istream& operator>>(istream& input, Array& thisArray) {
    char element, trash;
    int sz;
    input >> element >> trash >> sz;
    thisArray.setSize(sz);
    thisArray.setElement(element);
    return input;
}