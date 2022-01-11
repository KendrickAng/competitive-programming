#include <iostream>

int main() {
    int num, denom;
    int a, b;
    std::cin >> num >> denom;
    while (num != 0 && denom != 0) {
        a = num / denom;
        b = num % denom;
        std::cout << a << " " << b << " / " << denom << std::endl;
        std::cin >> num >> denom;
    }
}