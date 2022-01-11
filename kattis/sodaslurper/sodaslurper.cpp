#include <iostream>

int e, f, c;

int main() {
    std::cin >> e >> f >> c;
    int bottles = e + f;
    int sodas = 0;
    while (bottles >= c) {
        bottles -= c;
        sodas++;
        bottles++;
    }
    std::cout << sodas << std::endl;
}