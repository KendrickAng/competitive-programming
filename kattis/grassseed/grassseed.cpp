#include <iostream>
#include <iomanip>

int main() {
    double c, L, w, l;
    double total = 0;
    std::cin >> c >> L;
    for (int i = 0; i < L; i++) {
        std::cin >> w >> l;
        total += w * l * c;
    }
    std::cout << std::setprecision(15) << total << std::endl;
}