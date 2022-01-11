#include <iostream>

int main() {
    int max_idx = -1;
    int max_pts = -1;
    for (int i = 1; i < 6; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int tmp;
            std::cin >> tmp;
            sum += tmp;
        }
        if (max_idx != -1 && max_idx != -1) {
            if (sum > max_pts) {
                max_idx = i;
                max_pts = sum;
            }
        } else {
            max_idx = i;
            max_pts = sum;
        }
    }
    std::cout << max_idx << ' ' << max_pts;
}