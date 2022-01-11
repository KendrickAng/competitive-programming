#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<std::string> s{};
    std::string str;
    while (std::cin >> str) {
        if (s.find(str) != s.end()) {
            std::cout << "no\n";
            return 0;
        }
        s.insert(str);
    }
    std::cout << "yes\n";
}