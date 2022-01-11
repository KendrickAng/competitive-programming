#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector lst{a, b, c};
    std::sort(lst.begin(), lst.end());
    if (lst[2] - lst[1] == lst[1] - lst[0]) {
        std::cout << lst[2] + (lst[2] - lst[1]) << std::endl;
    } else if (lst[2] - lst[1] > lst[1] - lst[0]) {
        std::cout << lst[1] + (lst[1] - lst[0]) << std::endl;
    } else {
        std::cout << lst[0] + (lst[2] - lst[1]) << std::endl;
    }
}