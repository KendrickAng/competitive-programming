#include <iostream>
#include <cmath>

int main() {
    double n;
    std::cin >> n;

    n = log2(n);
    n = ceil(n);
    n++;

    std::cout << n << std::endl;
}