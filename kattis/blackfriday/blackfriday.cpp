#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> people{};
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        people.push_back(a);
    }
    int maxIdx = -1;
    int maxVal = -1;
    for (int i = 0; i < n; i++) {
        int val = people[i];
        if (val > maxVal) {
            bool dup = false;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (people[i] == people[j]) {
                    dup = true;
                    break;
                }
            }
            if (!dup) {
                maxVal = val;
                maxIdx = i;
            }
        }
    }
    if (maxIdx == -1) {
        std::cout << "none" << std::endl;
    } else {
        std::cout << maxIdx + 1 << std::endl;
    }
}