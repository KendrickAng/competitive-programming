#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> arr{};
    int n, tmp;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    std::sort(arr.rbegin(), arr.rend());

    long ret = 0;
    for (int i = 2; i < arr.size(); i += 3) {
        ret += arr[i];
    }
    std::cout << ret << std::endl;
}