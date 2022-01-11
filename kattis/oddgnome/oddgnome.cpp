#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int g, curr, next;
        std::cin >> g;
        std::cin >> curr;
        bool answered = false;
        for (int j = 1; j < g; j++) {
            std::cin >> next;
            if (!answered && next - curr != 1) {
                std::cout << j << std::endl;
                answered = true;
            }
            curr = next;
        }
    }
}