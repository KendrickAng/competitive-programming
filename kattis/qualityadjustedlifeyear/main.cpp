#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    float a, b, total;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        std::cin >> b;
        total += a * b;
    }
    std::cout << total << std::endl;
}