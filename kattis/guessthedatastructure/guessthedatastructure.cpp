#include <iostream>
#include <queue>
#include <stack>
#include <numeric>

int main() {
    int n;
    while (std::cin >> n) {
        bool sqpq[3] = {true, true, true};
        std::priority_queue<int> pq{};
        std::queue<int> q{};
        std::stack<int> st{};
        for (int i = 0; i < n; i++) {
            int a, b;
            std::cin >> a >> b;
            if (a == 1) {
                pq.push(b);
                q.push(b);
                st.push(b);
            }
            if (a == 2) {
                if (pq.empty()) {
                    sqpq[2] = false;
                } else {
                    int e = pq.top(); pq.pop();
                    if (e != b) sqpq[2] = false;
                }
                if (q.empty()) {
                    sqpq[1] = false;
                } else {
                    int e = q.front(); q.pop();
                    if (e != b) sqpq[1] = false;
                }
                if (st.empty()) {
                    sqpq[0] = false;
                } else {
                    int e = st.top(); st.pop();
                    if (e != b) sqpq[0] = false;
                }
            }
        }
        int sum = 0;
        sum = std::accumulate(sqpq, sqpq+3, sum);
        if (sum == 0) {
            std::cout << "impossible" << std::endl;
        } else if (sum > 1) {
            std::cout << "not sure" << std::endl;
        } else if (sum == 1) {
            if (sqpq[0]) std::cout << "stack" << std::endl;
            if (sqpq[1]) std::cout << "queue" << std::endl;
            if (sqpq[2]) std::cout << "priority queue" << std::endl;
        }
    }
}
