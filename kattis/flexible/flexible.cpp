#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int w, p;
    std::cin >> w >> p;
    std::vector<int> a{};
    a.push_back(0);
    for (int i = 0; i < p; i++) {
        int b; std::cin >> b;
        a.push_back(b);
    }
    a.push_back(w);
    std::sort(a.begin(), a.end());
    std::set<int> c{};
    for (int i = 0; i < a.size(); i++) {
        for (int j = i+1; j < a.size(); j++) {
            c.insert(a[j]-a[i]);
        }
    }
    bool first = true;
    for (auto a: c) {
        if (first) {
            first = false;
        } else {
            std::cout << " ";
        }
        std::cout << a;
    }
}