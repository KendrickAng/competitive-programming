#include <iostream>
#include <cmath>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::max(b-a, c-b) - 1 << std::endl;
}