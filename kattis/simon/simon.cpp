#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::getline(std::cin, s);
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, s);
        if (s.substr(0, 10) == "simon says") {
            if (s.length() <= 11) {
                std::cout << std::endl;
            } else {
                std::cout << s.substr(11) << std::endl;
            }
        } else {
            std::cout << std::endl;
        }
    }
}