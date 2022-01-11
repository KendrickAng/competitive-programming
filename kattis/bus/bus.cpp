#include <iostream>

int main() {
    int n, stops;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> stops;
        double passengers = 0.0;
        for (int j = 0; j < stops; j++) {
            passengers = (passengers + 0.5) * 2;
        }
        std::cout << (int) passengers << std::endl;
    }
}