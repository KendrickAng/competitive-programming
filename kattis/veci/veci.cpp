#include <iostream>
#include <unordered_map>
#include <algorithm>

bool samedigits(int a, int b) {
    std::string aa = std::to_string(a);
    std::string bb = std::to_string(b);
    std::sort(aa.begin(), aa.end());
    std::sort(bb.begin(), bb.end());
    return aa == bb;
}

int main() {
    int x;
    std::cin >> x;
    int tmp = x;
    int prev = -1;
    int curr;
    bool solvable = false;
    while (tmp > 0) {
        curr = tmp % 10;
        tmp /= 10;
        if (curr < prev) solvable = true;
        prev = curr;
    }
    if (!solvable) {
        std::cout << 0 << std::endl;
        return 0;
    }
    for (int i = x+1; ;i++) {
        if (samedigits(i, x)) {
            std::cout << i << std::endl;
            break;
        }
    }
}