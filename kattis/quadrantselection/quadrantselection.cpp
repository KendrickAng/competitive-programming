#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    if (x > 0) {
        if (y > 0) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 4 << std::endl;
        }
    } else {
        if (y > 0) {
            std::cout << 2 << std::endl;
        } else {
            std::cout << 3 << std::endl;
        }
    }
}