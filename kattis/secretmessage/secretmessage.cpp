#include <iostream>
#include <string>
#include <cmath>
#include <vector>

int main() {
    int n; std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string str; std::cin >> str;
        int l = str.length();
        int s = 1;
        while (std::pow(s, 2) < l) {
            s++;
        }
        int m = std::pow(s, 2);
        for (int i = 0; i < m-l; i++) {
            str.push_back('*');
        }
        std::vector<std::vector<char>> table{};
        int k = std::sqrt(m);
        // fill the table
        int idx = 0;
        for (int r = 0; r < k; r++) {
            table.push_back(std::vector<char>{});
            for (int c = 0; c < k; c++) {
                table[r].push_back(str[idx++]);
            }
        }
        std::vector<std::vector<char>> copy{};
        for (int r = 0; r < k; r++) {
            copy.push_back(std::vector<char>{});
            copy[r].resize(k);
        }
        // rotate the table clockwise 90 degrees
        for (int r = 0; r < k; r++) {
            for (int c = 0; c < k; c++) {
                copy[c][k-1-r] = table[r][c];
            }
        }
        for (int r = 0; r < k; r++) {
            for (int c = 0; c < k; c++) {
                if (copy[r][c] != '*') {
                    std::cout << copy[r][c];
                }
            }
        }
        std::cout << std::endl;
    }
}