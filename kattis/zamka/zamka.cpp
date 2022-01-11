#include <iostream>

int sum_digits(int n) {
    int ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    int L, D, X;
    std::cin >> L >> D >> X;
    for (int i = L; i <= D; i++) {
        if (sum_digits(i) == X) {
            std::cout << i << std::endl;
            break;
        }
    }
    for (int i = D; i <= L; i--) {
        if (sum_digits(i) == X) {
            std::cout << i << std::endl;
            break;
        }
    }
}