#include <iostream>

int limit = 210;

int main() {
    int K, N, T;
    char status;
    int time = 0;
    std::cin >> K >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> T >> status;
        time += T;
        if (time >= limit) {
            std::cout << K << std::endl;
            return 0;
        }
        if (status == 'T') {
            K += 1;
            if (K > 8) {
                K = 1;
            }
        }
    }
}