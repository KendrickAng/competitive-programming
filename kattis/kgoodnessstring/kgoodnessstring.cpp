#include <iostream>
#include <string>
#include <cmath>

int goodness(std::string s) {
    int score = 0;
    for (int i = 0; i < s.size()/2; i++) {
        if (s[i] != s[s.size()-1-i]) {
            score++;
        }
    }
    return score;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, k;
        std::cin >> n >> k;
        std::string str = "";
        char c;
        for (int j = 0; j < n; j++) {
            std::cin >> c;
            str.push_back(c);
        }
        // calculate score
        int score = goodness(str);
        int ops = std::abs(k - score);
        std::cout << "Case #" << i << ": " << ops << std::endl;
    }
}
