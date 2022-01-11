#include <iostream>

int main() {
    int n, start, end;
    bool hasFood[366] = { 0 };
    for (int i = 0; i < n; i++) {
        std::cin >> start >> end;
        for (int j = start; j <= end; j++) {
            hasFood[j] = true;
        }
    }
    int total = 0;
    for (auto& b: hasFood) {
        if (b) {
            total += 1;
        }
    }
    std::cout << total << std::endl;
}