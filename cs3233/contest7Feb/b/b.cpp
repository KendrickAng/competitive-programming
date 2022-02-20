#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using ll = long long;

#define var(x) {cout << #x << " = " << x << " " << endl;}
#define var2(x,y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define var3(x,y,z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}

const int OFFSET = 50000;

// ii rotate90(int x, int y) {
//     return {y, -x};
// }

// struct hasher {
//     size_t operator() (const ii &p) const {
//         return ((p.first+OFFSET) + 1e6) * 1e9 + ((p.second+OFFSET) + 1e6);
//     }
// };

ll hasher(int x, int y) {
    x += OFFSET;
    y += OFFSET;
    // return ((ll) x + 1e6) * 1e9 + (y + 1e6);
    return ((x + y)*(x + y + 1)/2) + y;
}

void solve() {
    int n; cin >> n;
    
    // read points, create count of points
    vector<ii> points(n);
    unordered_map<ll, int> cnt;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cnt[hasher(x, y)]++;
        points[i] = {x, y};
    }

    // iterate all possible points, generate squares
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            auto &[ax, ay] = points[i];
            auto &[bx, by] = points[j];

            // first square
            int xoff = ay - by;
            int yoff = -(ax-bx);
            // const auto &[xoff, yoff] = rotate90(ax-bx, ay-by);
            int cx = ax + xoff;
            int cy = ay + yoff;
            int dx = bx + xoff;
            int dy = by + yoff;

            ll h1 = hasher(cx, cy);
            ll h2 = hasher(dx, dy);
            if (cnt.find(h1) != cnt.end() && cnt.find(h2) != cnt.end()) {
                ans += cnt[h1] * cnt[h2];
            }

            // second square
            int xoff2 = by-ay;
            int yoff2 = -(bx-ax);
            // const auto &[xoff2, yoff2] = rotate90(bx-ax, by-ay);
            int cx2 = ax + xoff2;
            int cy2 = ay + yoff2;
            int dx2 = bx + xoff2;
            int dy2 = by + yoff2;

            h1 = hasher(cx2, cy2);
            h2 = hasher(dx2, dy2);
            if (cnt.find(h1) != cnt.end() && cnt.find(h2) != cnt.end()) {
                ans += cnt[h1] * cnt[h2];
            }

            // ans += cnt[hasher(cx2, cy2)] * cnt[hasher(dx2, dy2)];
        }
    }

    cout << ans/4 << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}
