#include <iostream>
#include <cstdlib>

int main() {
    long long int a, b;
    while(std::cin >> a && std::cin >> b) {
        std::cout << std::abs(a - b) << std::endl;
    }
}
