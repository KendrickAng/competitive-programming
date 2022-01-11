#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        int total_votes = 0;
        int max_votes = -1;
        int max_idx = -1;
        std::vector<int> votes{};
        std::cin >> N;
        for (int j = 0; j < N; j++) {
            int tmp;
            std::cin >> tmp;
            votes.push_back(tmp);
            total_votes += tmp;
            if (tmp > max_votes) {
                max_idx = j;
                max_votes = tmp;
            }
        }
        // all votes equal
        int count = 0;
        for (const auto &a: votes) {
            if (a == max_votes) {
                count ++;
            }
        }
        if (count > 1) {
            std::cout << "no winner" << std::endl;
        } else {
            // majority or minority winner
            if (max_votes > (double) total_votes / 2) {
                std::cout << "majority winner " << max_idx + 1 << std::endl;
            } else {
                std::cout << "minority winner " << max_idx + 1 << std::endl;
            }
        }
    }
}