#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int c;
    std::cin >> c;
    for (int i = 0 ; i < c; i++) {
        int n;
        double total = 0.0;
        std::cin >> n;
        std::vector<int> scores{};
        for (int j = 0; j < n; j++) {
            int score; std::cin >> score;
            scores.push_back(score);
            total += score;
        }
        double avg = total / scores.size();
        int above = 0;
        for (auto a: scores) {
            if (a > avg) above++;
        }
        std::cout << std::fixed << std::setprecision(3);
        std::cout << (double) above/scores.size() *100 << '%' << std::endl;
    }
}