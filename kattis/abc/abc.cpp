#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<int> lst{};
    std::string s;
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cin >> s;
    lst.push_back(a);
    lst.push_back(b);
    lst.push_back(c);
    std::sort(lst.begin(), lst.end());
    int first = true;
    for (char c: s) {
        if (first) {
            first = false;
        } else {
            std::cout << " ";
        }
        if (c == 'A') std::cout << lst[0];
        if (c == 'B') std::cout << lst[1];
        if (c == 'C') std::cout << lst[2];
    }
    std::cout << std::endl;
}