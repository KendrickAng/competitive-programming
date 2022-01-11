#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int prev, curr;
        std::cin >> prev >> curr;
        int imported = 0;
        while (curr != 0) {
            if (prev * 2 < curr) {
                imported += curr - prev*2;
            }
            prev = curr;
            std::cin >> curr;
        }
        std::cout << imported << std::endl;
    }
}