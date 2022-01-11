#include <iostream>
#include <string>
#include <algorithm>
#include <string>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int A = std::stoi(a);
    int B = std::stoi(b);
    if (A > B) {
        std::cout << A << std::endl;
    } else {
        std::cout << B << std::endl;
    }
}
