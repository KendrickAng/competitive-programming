#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        if (tmp % 2 == 0) {
            std::cout << tmp << " is even" << std::endl;
        } else {
            std::cout << tmp << " is odd" << std::endl;
        }
    }
}