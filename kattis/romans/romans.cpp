#include <iostream>

int main() {
    float X;
    std::cin >> X;
    std::cout << (int) (X * 1000 * 5280/4854 + 0.5) << std::endl;
}