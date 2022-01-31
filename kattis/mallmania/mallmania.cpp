#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int p1; cin >> p1;
        if (p1 == 0) break;

        vector<ii> first(p1);
        for (int i = 0; i < p1; i++) {
            int a, b; cin >> a >> b;
            first[i] = {a, b};
        }

        int p2; cin >> p2;
        vector<ii> second(p2);
        for (int i = 0; i < p2; i++) {
            int a, b; cin >> a >> b;
            second[i] = {a, b};
        }

        int ans = INT_MAX;
        for (int i = 0; i < p1; i++) {
            for (int j = 0; j < p2; j++) {
                auto [x1, y1] = first[i];
                auto [x2, y2] = second[j];
                ans = min(ans, abs(x1-x2)+abs(y1-y2));
            }
        }
        cout << ans << endl;
    }
}