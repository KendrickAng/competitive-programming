#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;
        std::vector<int> original{};
        for (int j = 0; j < m; j++) {
            int tmp;
            std::cin >> tmp;
            original.push_back(tmp);
        }
        // check
        bool ok = true;
        // check arithmetic
        int diff = original[1] - original[0];
        for (int i = 1; i < original.size(); i++) {
            if (diff != original[i] - original[i-1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            std::cout << "arithmetic" << std::endl;
            continue;
        }

        // check permuted arithmetic
        ok = true;
        std::sort(original.begin(), original.end());
        diff = original[1] - original[0];
        for (int i = 1; i < original.size(); i++) {
            if (original[i] - original[i - 1] != diff) {
                ok = false;
                break;
            }
        }
        if (ok) {
            std::cout << "permuted arithmetic" << std::endl;
            continue;
        }

        std::cout << "non-arithmetic" << std::endl;
    }
}