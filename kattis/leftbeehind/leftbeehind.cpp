#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    while (!(x == 0 && y == 0)) {
        std::string out;
        if (x + y == 13) {
            out = "Never speak again.";
        } else if (x > y) {
            out = "To the convention.";
        } else if (x < y) {
            out = "Left beehind.";
        } else {
            out = "Undecided.";
        }
        std::cout << out << std::endl;
        std::cin >> x >> y;
    }
}
