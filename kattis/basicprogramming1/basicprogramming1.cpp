#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

int main() {
    int N, t;
    // at least size 3
    std::vector<int> A{};
    std::cin >> N >> t;
    for (int i = 0; i < N; i++) {
        int tmp;
        std::cin >> tmp;
        A.push_back(tmp);
    }
    // check value of t
    if (t == 1) {
        std::cout << 7 << std::endl;
    }
    else if (t == 2) {
        if (A[0] > A[1]) {
            std::cout << "Bigger" << std::endl;
        } else if (A[0] == A[1]) {
            std::cout << "Equal" << std::endl;
        } else if (A[0] < A[1]) {
            std::cout << "Smaller" << std::endl;
        }
    }
    else if (t == 3) {
        // median is the value separating the higher and lower portion of data
        std::sort(A.begin(), A.begin()+3);
        std::cout << A[1] << std::endl;
    }
    else if (t == 4) {
        long long int total = 0;
        for (auto &a: A) {
            total += a;
        }
        std::cout << total << std::endl;
    }
    else if (t == 5) {
        long long int evenTotal = 0;
        for (auto &a: A) {
            if (a % 2 == 0) {
                evenTotal += a;
            }
        }
        std::cout << evenTotal << std::endl;
    }
    else if (t == 6) {
        std::string out = "";
        for (int i = 0; i < A.size(); i++) {
            out += (char) ((A[i] % 26) + ((int) 'a'));
        }
        std::cout << out << std::endl;
    }
    else if (t == 7) {
        int i = 0;
        bool visited[200000]{};
        while (true) {
            if (visited[i]) {
                // already seen before, cyclic!
                std::cout << "Cyclic" << std::endl;
                break;
            }
            if (i < 0 || i >= N) {
                std::cout << "Out" << std::endl;
                break;
            }
            if (i == N-1) {
                std::cout << "Done" << std::endl;
                break;
            }
            visited[i] = true;
            i = A[i];
        }
    }
}