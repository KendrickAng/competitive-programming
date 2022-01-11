#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x1, y1, x2, y2, p;
    std::cin >> x1;
    while (x1 != 0) {
        std::cin >> y1 >> x2 >> y2 >> p;
    }
    std::cout << std::fixed << std::setprecision(10);
    double a = std::pow(std::abs(x1 - x2), p);
    double b = std::pow(std::abs(y1-y2), p);
    std::cout << std::pow(a+b, 1.0/p) << std::endl;
}