#include <iostream>
#include <cmath>

int main() {
    int n;
    double w, h;
    std::cin >> n >> w >> h;
    double limit = std::sqrt(w * w + h * h);
    int length;
    for (int i = 0; i < n; i++) {
        std::cin >> length;
        if (length <= limit) {
            std::cout << "DA\n";
        } else {
            std::cout << "NE\n";
        }
    }
}