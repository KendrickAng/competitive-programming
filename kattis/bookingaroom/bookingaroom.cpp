#include <iostream>

int main() {
    int r, n;
    std::cin >> r >> n;
    bool booked[r+1]{};
    booked[0] = true;
    for (int i = 0; i < n; i++) {
        int idx;
        std::cin >> idx;
        booked[idx] = true;
    }
    for (int i = 1; i < r+1; i++) {
        if (!booked[i]) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << "too late" <<std::endl;
}