#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double a, b, c;
    double i, j, k;
    std::cin >> a >> b >> c >> i >> j >> k;
    double denom = std::min(a/i, std::min(b/j, c/k));
    std::cout << std::fixed << std::setprecision(6);
    std::cout << a-denom*i << " " << b-denom*j << " " << c-denom*k << std::endl;
}