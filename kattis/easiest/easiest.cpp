#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> mem{};

int sumdigits(int n) {
    if (mem.find(n) != mem.end()) {
        return mem[n];
    }

    int total = 0;
    while (n > 0) {
        total += n % 10;
        n /= 10;
    }
    mem[n] = total;

    return total;
}

int main() {
    int N;
    std::cin >> N;
    while (N != 0) {
        int p = 11;
        while (true) {
            int np = sumdigits(N*p);
            int nn = sumdigits(N);
            if (np == nn) {
                std::cout << p << std::endl;
            }
            break;
            p++;
        }
        std::cin >> N;
    }
}