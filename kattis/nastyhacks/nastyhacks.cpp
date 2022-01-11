#include <iostream>

int main() {
    int n;
    double r, e, c;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> r >> e >> c;
        double diff = r - (e - c);
        if (diff < 0) {
            std::cout << "advertise" << std::endl;
        } else if (diff > 0) {
            std::cout << "do not advertise" << std::endl;
        } else {
            std::cout << "does not matter" << std::endl;
        }
    }
} 