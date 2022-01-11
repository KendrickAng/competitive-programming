#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        double n;
        std::cin >> n;
        std::cout << std::ceil(n / 400) << std::endl;
    }
}