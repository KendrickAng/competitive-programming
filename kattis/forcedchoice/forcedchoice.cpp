#include <iostream>
#include <unordered_set>

int main() {
    int n, p, s;
    std::cin >> n >> p >> s;
    for (int i = 0; i < s; i++) {
        int m; std::cin >> m;
        std::unordered_set<int> set{};
        for (int i = 0; i < m; i++) {
            int tmp; std::cin >> tmp;
            set.insert(tmp);
        }
        if (set.find(p) != set.end()) {
            std::cout << "KEEP" << std::endl;
        } else {
            std::cout << "REMOVE" << std::endl;
        }
    }
}