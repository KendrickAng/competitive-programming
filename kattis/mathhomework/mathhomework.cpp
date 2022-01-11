#include <iostream>

int main() {
    int b,d,c,l;
    std::cin >> b >> d >> c >> l;
    bool solved = false;

    for (int i = 0; i <= 250; i++) {
        for (int j = 0; j <= 250; j++) {
            for (int k = 0; k <= 250; k++) {
                if (b*i + d*j + c*k == l) {
                    solved = true;
                    std::cout << i << ' ' << j << ' ' << k << "\n";
                }
            }
        }
    }
    if (!solved) {
        std::cout << "impossible" << std::endl;
    }
}