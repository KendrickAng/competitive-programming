#include <iostream>
#include <map>
#include <cmath>

int main() {
    std::map<int, int> counter{};
    int N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            counter[i+j] ++;
        }
    }
    int mx = 0;
    for (auto [key, val]: counter) {
        mx = std::max(mx, val);
    }
    for (auto [key, val]: counter) {
        if (val == mx) {
            std::cout << key << std::endl;
        }
    }
}