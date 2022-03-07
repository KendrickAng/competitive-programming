#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int W; cin >> W;
    for (int i = 1; i < W; i++) {
        int remW = W - i;
        if (i % 2 == 0 and remW % 2 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
