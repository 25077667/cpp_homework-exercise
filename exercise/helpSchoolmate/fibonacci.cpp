#include <iostream>
typedef long double ld;

ld f(ld* (&storage), ld n) {
    if (!n)
        return 0;
    else if (storage[int(n)] != 0)
        return storage[int(n)];
    else
        return storage[int(n)] = f(storage, n - 2) + f(storage, n - 1);
}

int main() {
    ld *storage, input;
    std::cout << "How many numbers of fibonacci sequence you want to genetate?(max 23601)";
    std::cin >> input;
    storage = new ld[int(input + 1)];
    storage[0] = 0;
    storage[2] = storage[1] = 1;
    f(storage, input);
    for (int i = 0; i <= input; i++)
        std::cout << i << '\t' << storage[i] << std::endl;
    return 0;
}
