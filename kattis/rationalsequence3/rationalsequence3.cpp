#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, pair<int, int>> ans{};

pair<int, int> solve(int n) {
    if (ans.count(n)) {
        return ans[n];
    }
    pair<int, int> prev = solve(n/2);
    ans[n/2] = prev;
    int p = prev.first;
    int q = prev.second;
    pair<int, int> ret;
    if (n % 2 == 0) {
        ret = {p, (p+q)};
    } else {
        ret = {(p+q), q};
    }
    ans[n] = ret;
    return ret;
}

int main() {
    ans[1] = {1, 1};
    ans[2] = {1, 2};
    ans[3] = {2, 1};

    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int k, n;
        cin >> k >> n;
        pair<int, int> pp = solve(n);
        cout << k << " " << pp.first << "/" << pp.second << std::endl;
    }
}