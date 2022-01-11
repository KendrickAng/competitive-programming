#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    while (n != 0) {
        std::vector<int> a{};
        for (int i = 0; i < n; i++) {
            int tmp; std::cin >> tmp;
            a.push_back(tmp);
        }
        std::vector<int> aa(a);
        std::vector<int> b{};
        for (int i = 0; i < n; i++) {
            int tmp; std::cin >> tmp;
            b.push_back(tmp);
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::unordered_map<int, int> m{};
        for (int i = 0; i < a.size(); i++) {
            m[a[i]] = b[i];
        }
        for (auto a: aa) {
            std::cout << m[a] << std::endl;
        }
        std::cout << std::endl;
        std::cin >> n;
    }
}