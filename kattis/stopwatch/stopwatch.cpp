#include <iostream>

int main() {
    int n; std::cin >> n;
    if (n % 2 != 0) {
        std::cout << "still running" << std::endl;
    } else {
        int prev;
        int curr;
        int total = 0;
        for (int i = 0; i < n; i+=2) {
            std::cin >> prev >> curr;
            total += curr-prev;
        }
        std::cout << total << std::endl;
    }
}