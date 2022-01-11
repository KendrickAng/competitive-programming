#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s1;
    std::string s2;
    for (int i = 0; i< n; i++) {
        std::cin >> s1 >> s2;
        std::cout << s1 << std::endl;
        std::cout << s2 << std::endl;
        for (int j = 0; j < s1.size(); j++) {
            if (s1[j] == s2[j]) std::cout << '.';
            else std::cout << '*';
        }
        std::cout << std::endl << std::endl;
    }
}