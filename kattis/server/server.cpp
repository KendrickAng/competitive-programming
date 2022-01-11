#include <iostream>

int main() {
    int n, t;
    std::cin >> n >> t;
    int time = 0;
    int tasks = 0;
    for (int i = 0; i < n; i++) {
        int tmp; std::cin >> tmp;
        time += tmp;
        if (time > t) {
            std::cout << tasks << std::endl;
            return 0;
        }
        tasks ++;
    }
    std::cout << tasks << std::endl;
}