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
    bool accessor();  //what's in
    void mutator();   //modify contens
    void readFile();
    void initContens();
};
int main() {
    BoxOfProduce box;
    std::cout << "initial the Box" << std::endl;
    box.readFile();
    std::cout << "done" << std::endl;
    box.mutator();
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
    contens.push_back(selection.at(get_random_number()));
    contens.push_back(selection.at(get_random_number()));
    contens.push_back(selection.at(get_random_number()));
}
bool BoxOfProduce::accessor() {
    char tmp;
    std::cout << "The box contains (1)" << contens[0] << " (2)" << contens[1] << " (3)" << contens[2] << " " << std::endl;
    std::cout << "Enter q to cancel" << std::endl
              << "Enter c to change a bundle." << std::endl;
    std::cin >> tmp;
    return (tmp == 'c');
}
void BoxOfProduce::mutator() {
    while (accessor()) {
        int index;
        std::string subsitute;
        std::cout << "Enter index of item to change." << std::endl;
        std::cin >> index;
        std::cout << "Enter item to subsitute." << std::endl;
        std::cin >> subsitute;
        contens.at(index - 1) = subsitute;
    }
    std::cout << "The final contains" << std::endl
              << "The box contains (1)" << contens[0] << " (2)" << contens[1] << " (3)" << contens[2] << " " << std::endl;
}