#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::vector<int> days{};
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        days.push_back(t);
    }
    std::sort(days.rbegin(), days.rend());
    int mx = -1;
    int day = 1;
    for (int i: days) {
        mx = std::max(mx, i + day++);
    }
    std::cout << mx + 1 << std::endl;
}