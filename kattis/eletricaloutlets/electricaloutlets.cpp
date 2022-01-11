#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int plugs = 0;
        int n2 = 0;
        std::cin >> n2;
        for (int j = 0; j < n2; j++) {
            int temp;
            std::cin >> temp;
            plugs += temp;
        }
        std::cout << plugs - (n2-1) << std::endl;
    }
}