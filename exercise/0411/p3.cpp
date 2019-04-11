#include <iostream>
struct Point {
    int x, y;
};
struct Line {
    Point first, second;
    int vx, vy;
};
int main() {
    Line l[2];
    for (int i = 0; i < 2; i++) {
        std::cout << char('A' + i * 2) << std::endl;
        std::cin >> l[i].first.x >> l[i].first.y;
        std::cout << char('B' + i * 2) << std::endl;
        std::cin >> l[i].second.x >> l[i].second.y;
        l[i].vx = l[i].second.x - l[i].first.x;
        l[i].vy = l[i].second.y - l[i].first.y;
    }
    std::cout << ((l[0].vx * l[1].vx + l[0].vy * l[1].vy) ? "Not Vertical" : "Vertical") << std::endl;
    return 0;
}