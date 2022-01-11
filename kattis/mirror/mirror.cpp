#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++) {
        int r, c; std::cin >> r >> c;
        std::vector<std::vector<char>> arr{};
        arr.resize(r);
        for (auto &a: arr) a.resize(c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char tmp; std::cin >> tmp;
                arr[i][j] = tmp;
            }
        }
        std::cout << "Test " << i << std::endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                std::cout << arr[r-1-i][c-1-j];
            }
            std::cout << std::endl;
        }
    }
}