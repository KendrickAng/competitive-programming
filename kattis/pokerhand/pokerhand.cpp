#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int main() {
    std::string temp;
    std::unordered_map<char, int> map;
    while (std::cin >> temp) {
        map[temp[0]] += 1;
    }
    int max = 0;
    for (auto const& [key, val]: map) {
        max = std::max(max, val);
    }
    std::cout << max << std::endl;
}