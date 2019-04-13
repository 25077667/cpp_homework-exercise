#include <bits/stdc++.h>
int get_random_number() {
    std::random_device rd;
    std::mt19937_64 mt_rand(rd());
    return (mt_rand() % 5);
}
class BoxOfProduce {
    std::vector<std::string> contens;
    std::vector<std::string> selection;

   public:
    BoxOfProduce(){};
    void initContens();
    void readFile();
    friend std::ostream& operator<<(std::ostream& output, BoxOfProduce& thisBoxOfProduce);
    friend BoxOfProduce& operator+(BoxOfProduce& a, BoxOfProduce& b);
};
int main() {
    BoxOfProduce box1, box2;
    box1.readFile();
    box2.readFile();
    std::cout << box1 << std::endl
              << box2 << std::endl;
    std::cout << (box1 + box2) << std::endl;
}

void BoxOfProduce::readFile() {
    std::ifstream file;
    std::string tmp;
    file.open("produce.txt");
    while (file >> tmp)
        selection.push_back(tmp);
    initContens();
}
void BoxOfProduce::initContens() {
    for (int i = 0; i < get_random_number() * get_random_number() + 1; i++)
        contens.push_back(selection.at(get_random_number()));
}
BoxOfProduce& operator+(BoxOfProduce& a, BoxOfProduce& b) {
    for (std::vector<std::string>::iterator iter = b.contens.begin(); iter != b.contens.end(); iter++)
        a.contens.push_back(*iter);
    return a;
}

std::ostream& operator<<(std::ostream& output, BoxOfProduce& thisBoxOfProduce) {
    output << "The box contains:";
    for (std::vector<std::string>::iterator iter = thisBoxOfProduce.contens.begin(); iter != thisBoxOfProduce.contens.end(); iter++)
        output << " (" << iter - thisBoxOfProduce.contens.begin() + 1 << ") " << *iter;
    return output;
}