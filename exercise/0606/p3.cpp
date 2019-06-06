#include <fstream>
#include <iostream>
#include <random>
using namespace std;

int getRandom() {
    random_device rd;
    mt19937_64 mt_rand(rd());
    //printf("%d\n",mt_rand()%80);
    return mt_rand() % 52;
}

void selection_sort(int* arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        int index = i;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[index])
                index = j;
        }
        int tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;
    }
}

int main() {
    ofstream out("MyLottery");
    int selection;

    int* arr = new int[52];
    int* user = new int[6];
    for (int i = 0; i < 52; i++)
        arr[i] = i + 1;

    for (int i = 0; i < 10000; i++)
        swap(arr[getRandom()], arr[getRandom()]);

    while (cin >> selection && selection != -1) {
        cout << selection << "AAA" << endl;
        if (selection == 1) {
            //auto
            selection_sort(arr, 6);
            out << "c" << endl;
            for (int i = 0; i < 6; i++) {
                out << arr[i] << endl;
            }
            for (int i = 0; i < 10000; i++)
                swap(arr[getRandom()], arr[getRandom()]);
        } else {
            for (int i = 0; i < 6; i++) {
                int tmp;
                cin >> tmp;
                for (int j = 0; j < i; j++)
                    if (tmp == user[j]) {
                        i--;
                        continue;
                    }
                if (tmp > 52 || tmp <= 0) {
                    i--;
                    continue;
                }
                user[i] = tmp;
            }
            selection_sort(user, 6);
            out << "u" << endl;
            for (int i = 0; i < 6; i++) {
                out << user[i] << endl;
            }
        }
    } 
    delete[] user;
    delete[] arr;
    out.close();
    return 0;
}