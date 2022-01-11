#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

int C, R;

int main() {
    std::cin >> R >> C;
    std::cout << std::setprecision(20) << pow((R-C), 2) / pow(R, 2) * 100 << std::endl;
}