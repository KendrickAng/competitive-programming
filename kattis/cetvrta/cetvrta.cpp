#include <iostream>
#include <map>

int main() {
    std::map<int, int> x{};
    std::map<int, int> y{};
    for (int i = 0; i < 3; i++) {
        int a, b;
        std::cin >> a >> b;
        x[a]++;
        y[b]++;
    }
    for (auto [k,v]: x)  {
        if (v == 1) std::cout << k;
    }
    std::cout << " ";
    for (auto [k,v]: y) {
        if (v == 1) std::cout << k;
    }
    std::cout << std::endl;
}