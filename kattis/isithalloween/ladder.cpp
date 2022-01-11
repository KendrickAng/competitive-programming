#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main() {
    double h, v;
    std::cin >> h >> v;
    std::cout << (int)((h / sin(v * M_PI/180)) + 0.5) << std::endl;
}