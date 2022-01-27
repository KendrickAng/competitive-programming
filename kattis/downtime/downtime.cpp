#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k; cin >> n >> k;
    queue<int> q;
    int ans = 0;
    int freeSpace = 0;

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (freeSpace <= 0) {
            if (!q.empty() and q.front() <= t) {
                q.pop();
                freeSpace++;
            } else {
                ans++;
                freeSpace += k;
            }
        }
        freeSpace--;
        q.push(t + 1000);
    }

    cout << ans << endl;
}