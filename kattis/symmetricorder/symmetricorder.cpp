#include <iostream>
#include <vector>

int main() {
    int n;
    int count = 0;
    std::cin >> n;
    while (n != 0) {
        count ++;
        std::cout << "SET " << count << std::endl;
        std::vector<std::string> inc{};
        std::vector<std::string> dec{};
        for (int i = 0; i < n; i++) {
            std::string nxt;
            std::cin >> nxt;
            if (i % 2 == 0) inc.push_back(nxt);
            else dec.push_back(nxt);
        }
        for (auto a: inc) {
            std::cout << a << std::endl;
        }
        for (int i = dec.size()-1; i >= 0; i--) {
            std::cout << dec[i] << std::endl;
        }
        std::cin >> n;
    }
}