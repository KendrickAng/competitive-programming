#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, P;
    std::string tmp;
    std::cin >> N >> P;
    for (int i = 0; i < N; i++) {
        std::cin >> tmp;
    }
    std::cout << P << std::endl;
}