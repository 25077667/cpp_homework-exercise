#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    ifstream in1("seq1"), in2("seq2");
    priority_queue<int> pq;
    stack<int> s;

    if(in1.fail() || in2.fail())
        exit(1);
    
    while (!in1.eof() ) {
        int tmp;
        in1 >> tmp;
        cout << tmp <<endl;
        pq.push(tmp);
    }
    cout << endl;
    while (!in2.eof()) {
        int tmp;
        in2 >> tmp;
        cout << tmp << endl;
        pq.push(tmp);
    }

    while(!pq.empty()){
        s.push(pq.top());
        pq.pop();
    }
    cout <<endl;

    ofstream out1("merge");
    while(!s.empty()){
        cout << s.top() <<endl;
        out1<< s.top();
        s.pop();
    }
    out1.close();
    in1.close();
    in2.close();
    return 0;
}