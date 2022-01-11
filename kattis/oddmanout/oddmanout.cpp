#include <iostream>
#include <unordered_map>

int main() {
    int N;
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::unordered_map<int, int> counter{};
        int G;
        std::cin >> G;
        for (int j = 0; j < G; j++) {
            int id;
            std::cin >> id;
            counter[id] ++;
        }
        int alone = -1;
        for (auto [key, val]: counter) {
            if (val == 1) alone = key;
        }
        std::cout << "Case #" << i << ": " << alone << std::endl;
    }
}