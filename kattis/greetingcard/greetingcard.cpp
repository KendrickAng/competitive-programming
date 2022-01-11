#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

/*
Do this first in python to get all possible offsets

import math

for i in range(-2018, 2019):
    for j in range(-2018, 2019):
        if math.sqrt(i*i +j*j) == 2018:
            print(f"{i} {j}")
*/

int main() {
    int n; cin >> n;
    set<pair<long, long>> pts;
    vector<pair<long, long>> offsets;
    offsets.push_back({0, 2018});
    offsets.push_back({0, -2018});
    offsets.push_back({2018, 0});
    offsets.push_back({-2018, 0});
    offsets.push_back({1118, 1680});
    offsets.push_back({1118, -1680});
    offsets.push_back({1680, 1118});
    offsets.push_back({1680, -1118});
    offsets.push_back({-1680, -1118});
    offsets.push_back({-1680, 1118});
    offsets.push_back({-1118, -1680});
    offsets.push_back({-1118, 1680});

    // get points
    for (int i = 0; i < n; i++) {
        long x, y; cin >> x >> y;
        pts.insert({x, y});
    }

    int ans = 0;
    for (auto &pt: pts) {
        long x = pt.first;
        long y = pt.second;
        for (auto &offset: offsets) {
            long xx = offset.first;
            long yy = offset.second;
            if (pts.find({x+xx, y+yy}) != pts.end()) {
                ans++;
            }
        }
    }
    cout << ans / 2 << endl;
}