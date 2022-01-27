#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> indeg(n+1, 0);
    vector<int> outdeg(n+1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        outdeg[u]++;
        indeg[v]++;
    }

    bool hasWalk = true;
    int start = -1;
    int end = -1;
    for (int i = 1; i <= n; i++) {
        if (outdeg[i] == indeg[i]) {
            continue;
        } else if (outdeg[i] == indeg[i]+1) {
            if (start != -1) {
                cout << "no" << endl;
                return 0;
            }
            start = i;
        } else if (outdeg[i]+1 == indeg[i]) {
            if (end != -1) {
                cout << "no" << endl;
                return 0;
            }
            end = i;
        } else {
            cout << "no" << endl;
            return 0;
        }
    }

    if (start == -1 && end == -1) {
        cout << "anywhere" << endl;
    } else if (start != -1 && end != -1) {
        cout << start << ' ' << end << endl;
    } else {
        cout << "no" << endl;
    }
}