#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string x0;
    std::cin >> x0;
    while (x0 != "END") {
        if (x0 == "1") {
            std::cout << 1 << std::endl;
        } else {
            int x = x0.length();
            int xx = std::to_string(x).length();
            int i = 2;
            while (xx != x) {
                x = xx;
                xx = std::to_string(x).length();
                i++;
            }
            std::cout << i << std::endl;
        }
        std::cin >> x0;
    }
}