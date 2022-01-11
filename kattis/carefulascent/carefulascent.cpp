#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

struct Shield {
    int l;
    int u;
    double f;
};

int x, y, n;
vector<Shield> shields;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x >> y >> n;
    for (int i = 0; i < n; i++) {
        int l, u; double f;
        cin >> l >> u >> f;
        shields.push_back({ l, u, f });
    }
    sort(shields.begin(), shields.end(), [](Shield &a, Shield b) {
        return a.l < b.l;
    });

    double denom = 0.0;
    if (shields.empty()) {
        denom = y;
    } else {
        double prevU = 0;
        for (auto s: shields) {
            if (s.l != prevU) {
                denom += s.l - prevU;
            }
            prevU = s.u;
            denom += s.f * (s.u - s.l);
        }
        denom += y - shields[shields.size()-1].u;
    }

    cout << fixed << setprecision(10) << x / denom << endl;
}