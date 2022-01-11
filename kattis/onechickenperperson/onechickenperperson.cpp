#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    if (M > N) {
        if (M - N == 1) {
            std::cout << "Dr. Chaz will have 1 piece of chicken left over!\n";
        } else {
            std::cout << "Dr. Chaz will have " << M-N << " pieces of chicken left over!\n";
        }
    } else {
        if (N - M == 1) {
            std::cout << "Dr. Chaz needs 1 more piece of chicken!\n";
        } else {
            std::cout << "Dr. Chaz needs " << N-M << " more pieces of chicken!\n";
        }
    }
}
