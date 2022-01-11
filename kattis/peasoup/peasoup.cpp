#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        bool has_pea_soup = false;
        bool has_pancakes = false;
        int k;
        std::string name, food;
        std::cin >> k;
        // remove prepended whitespace
        std::getline(std::cin >> std::ws, name);
        for (int j = 0; j < k; j++) {
            std::getline(std::cin, food);
            if (food == "pea soup") {
                has_pea_soup = true;
            }
            if (food == "pancakes") {
                has_pancakes = true;
            }
        }
        if (has_pancakes && has_pea_soup) {
            std::cout << name << std::endl;
            return 0;
        }
    }
    std::cout << "Anywhere is fine I guess" << std::endl;
}