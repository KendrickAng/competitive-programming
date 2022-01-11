#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

std::string ORDER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int main() {
    // create letter -> idx, idx -> letter maps
    std::unordered_map<char, int> li{};
    for (int i = 0; i < ORDER.size(); i++) {
        li[ORDER[i]] = i;
    }
    int n;
    std::cin >> n;
    while (n != 0) {
        std::string s;
        std::cin >> s;
        std::reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            s[i] = ORDER[(li[s[i]]+n) % ORDER.size()];
        }
        std::cout << s << std::endl;
        std::cin >> n;
    }
}