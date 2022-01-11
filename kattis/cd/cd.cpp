#include <iostream>
#include <unordered_set>

int main() {
    int m, n;
    std::cin >> m >> n;
    while (m != 0 && n != 0) {
        std::unordered_set<int> jack{};
        std::unordered_set<int> jill{};
        for (int i = 0; i < m; i++) {
            int tmp; std::cin >> tmp;
            jack.insert(tmp);
        }
        for (int i = 0; i < n; i++) {
            int tmp; std::cin >> tmp;
            jill.insert(tmp);
        }
        int dups = 0;
        for (auto &a: jack) {
            if (jill.find(a) != jill.end()) {
                dups ++;
            }
        }
        std::cout << dups << std::endl;
    }
}