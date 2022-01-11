#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;
using iii = tuple<int, int, int>;

void print_queue(priority_queue<iii> q) { // NB: pass by value so the print uses a copy
    auto &[a,b,c] = q.top();
    cout << "QUEUE " << a << " " << b << " " << c << endl;
}

int main() {
    int n, t; cin >> n >> t;
    bool served[n] = {false};
    vector<priority_queue<iii>> candidates(t+1, priority_queue<iii>{});
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        for (int j = 0; j <= b; j++) {
            candidates[j].push({a,b,i});
        }
    }

    long long time = 0;
    long long money = 0;
    while (time <= t) {
        priority_queue<iii> &q = candidates[time];
        while (!q.empty()) {
            auto &[a, b, c] = q.top(); q.pop();
            cout << a << " " << b << " " << c << endl;
            if (!served[c]) {
                served[c] = true;
                money += a;
                break;
            }
        }
        time++;
    }

    cout << money << endl;
}