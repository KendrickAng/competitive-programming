#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    int currVersion = 0;
    int globalWealth = 0; // all start with zero wealth first

    // wealth, version, all start w/ 0 wealth, also zero-indexed
    vector<pair<int, int>> model(n+1, pair<int, int>(0, 0));

    for (int i = 0; i < q; i++) {
        string cmd; cin >> cmd;
        if (cmd == "SET") {
            int i, x; cin >> i >> x;
            auto &[wealth, version] = model[i];
            wealth = x;
            version = currVersion;
        } else if (cmd == "PRINT") {
            int i; cin >> i;
            auto &[wealth, version] = model[i];

            // lazy update
            if (currVersion > version) {
                // cout << "HI" << endl;
                version = currVersion;
                wealth = globalWealth;
            }

            cout << wealth << endl;
        } else { // RESTART
            int x; cin >> x;

            currVersion++;
            globalWealth = x;
        }
    }
}