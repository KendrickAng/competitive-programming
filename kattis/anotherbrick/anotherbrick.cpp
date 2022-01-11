#include <iostream>

int h, w, n;
int b_width;
int curr_width = 0;
int curr_height = 0;

int main() {
    std::cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> b_width;
        // brick too long - leave.
        if (curr_width + b_width > w) {
            std::cout << "NO" << std::endl;
            return 0;
        }
        // brick ok - place on current wall
        if (curr_width + b_width <= w) {
            curr_width += b_width;
            if (curr_width == w) {
                // completed one layer
                curr_height++;
                curr_width = 0;
                if (curr_height == h) {
                    // complted the wall
                    std::cout << "YES" << std::endl;
                    return 0;
                }
            }
        }
    }
    // not enough bricks to finish wall - leave.
    std::cout << "NO" << std::endl;
}