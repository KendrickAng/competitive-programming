#include <iostream>
#include <vector>

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<int> money{};
    money.resize(t+1);
    for (int i = 0; i < n; i++) {
        int ci, ti;
        std::cin >> ci >> ti;
        for (int time = ti; time >= 0; time--) {
            if (money[time] < ci) {
                std::swap(money[time], ci);
            }
        }
        for (auto a: money) std::cout << a << " ";
        std::cout << std::endl;
    }
    int total = 0;
    for (auto a: money) {
        total += a;
    }
    std::cout << total << std::endl;
}