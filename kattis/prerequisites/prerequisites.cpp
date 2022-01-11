#include <iostream>
#include <set>

int main() {
    int k, m;
    std::cin >> k;
    while (k != 0) {
        std::cin >> m;
        std::set<int> courses{};
        for (int i = 0; i < k; i++) {
            int tmp; std::cin >> tmp;
            courses.insert(tmp);
        }
        bool fulfilled = true;
        for (int i = 0; i < m; i++) {
            int c, r; std::cin >> c >> r;
            int match = 0;
            for (int j = 0; j < c; j++) {
                int tmp; std::cin >> tmp;
                if (courses.find(tmp) != courses.end()) {
                    match++;
                }
            }
            if (match < r) fulfilled = false;
        }
        if (fulfilled) std::cout << "yes\n";
        else std::cout << "no\n";

        std::cin >> k;
    }
}