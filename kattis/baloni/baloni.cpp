#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> balloons;
    unordered_map<int, int> h2n;
    for (int i = 0; i < n; i ++) {
        int tmp; cin >> tmp;
        balloons.push_back(tmp);
    }
    // shoot multiple arrows
    for (int h: balloons) {
        if (h2n[h] > 0) {
            // have an arrow
            h2n[h]--;
            h2n[h-1]++;
        } else {
            // no arrow, shoot a new one
            h2n[h-1]++;
        }
    }
    int ans = 0;
    for (auto &[k,v]: h2n) {
        ans += v;
    }
    cout << ans << endl;
}