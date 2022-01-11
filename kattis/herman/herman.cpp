#include <cmath>
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int R;
    std::cin >> R;
    std::cout << std::setprecision(15) << M_PI * R * R << std::endl;
    std::cout << std::setprecision(15) << 0.5 * R * R * 4 << std::endl;
}
