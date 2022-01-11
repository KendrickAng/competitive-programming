#define _USE_MATH_DEFINES
#include <iostream>
#include <unordered_set>
#include <cmath>

int main() {
    int n;
    double v, deg, x, h1, h2;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> v >> deg >> x >> h1 >> h2;
        double radians = deg * M_PI / 180;
        double t = x / (v * cos(radians));
        double y = (v * t * sin(radians)) - (0.5 * 9.81 * t * t);
        if (y - h1 >= 1 && h2 - y >= 1) {
            std::cout << "Safe" << std::endl;
        } else {
            std::cout << "Not Safe" << std::endl;
        }
    }
}