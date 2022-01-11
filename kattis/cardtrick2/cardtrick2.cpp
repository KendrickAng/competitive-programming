#include <iostream>
#include <deque>

int main() {
    int T, n;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> n;
        std::deque<int> q = {};
        while (n > 0) {
            q.push_front(n);
            for (int j = 0; j < n; j++) {
                int tmp = q.back();
                q.pop_back();
                q.push_front(tmp);
            }
            n--;
        }
        int first = true;
        for (int a: q) {
            if (!first) {
                std::cout << ' ';
            } else {
                first = false;
            }
            std::cout << a;
        }
        std::cout << std::endl;
    }
}