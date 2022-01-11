#include <iostream>
#include <iomanip>      // std::setprecision

int main() {
    int n = 0;
    std::cin >> n;
    int totalBats = 0, totalScore = 0;
    for (int i = 0; i < n; i++) {
        int score;
        std::cin >> score;
        if (score != -1) {
            totalBats ++;
            totalScore += score;
        }
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(14) << (double) totalScore / totalBats << std::endl;
}