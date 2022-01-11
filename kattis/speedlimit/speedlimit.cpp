#include <iostream>

int main() {
    int n;
    std::cin >> n; 
    while (n != -1) {
        int speed, curr;
        int prev = 0;
        int miles = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> speed >> curr;
            miles += speed * (curr-prev);
            prev = curr;
        }
        std::cout << miles << " miles" << std::endl;
        std::cin >> n;
    }
}