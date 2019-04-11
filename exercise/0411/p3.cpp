#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    int x,y;
};

struct Line{
    Point first,second;
    int vx,vy;
};

int main() {
    Line a,b;
    char trash;
    cin >> trash;
    cin >> a.first.x >> a.first.y;
    cin >> trash;
    cin >> a.second.x >> a.second.y;
    cin >> trash;
    cin >> b.first.x >> b.first.y;
    cin >> trash;
    cin >> b.second.x >> b.second.y;
    a.vx = a.second.x - a.first.x;
    a.vy = a.second.y - a.first.y;
    b.vx = b.second.x - b.first.x;
    b.vy = b.second.y - b.first.y;
    if(a.vx *b.vx +a.vy*b.vy == 0)
        cout<<"vertical"<<endl;
    else
        cout<<"Not Vertical"<<endl;
    
    return 0;
}