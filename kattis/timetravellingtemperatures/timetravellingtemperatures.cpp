#include <iostream>
#include <iomanip>

int main() {
    int X, Y;
    std::cin >> X >> Y;
    // multiple points
    if (X == 0 && Y == 1) {
        std::cout << "ALL GOOD" << std::endl;
    } else if (Y == 1) {
        // cannot reach
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        // one pint
        std::cout << std::setprecision(15) << X / (1.0-Y) << std::endl;
    }
}
