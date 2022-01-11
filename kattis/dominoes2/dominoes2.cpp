#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> AL;
vector<bool> visited;

// C++ prohibits passing a temporary object as a non-const reference param
void print(const string &s) {
    cout << s;
}

void print(vector<vector<int>> &v) {
    for (auto a: v) {
        for (auto b: a) {
            cout << b << " ";
        }
        cout << endl;
    }
}

void printVec(vector<bool> &v) {
    for (auto a: v) cout << a << " ";
    cout << endl;
}

void dfs(int idx) {
    visited[idx] = true;
    for (auto &neigh: AL[idx]) {
        if (!visited[neigh]) {
            dfs(neigh);
        }
    }
}

void solve() {
    int n, m, l; cin >> n >> m >> l;
    AL = vector<vector<int>>(n, vector<int>()); // 1-indexed for easy access
    visited = vector<bool>(n, false); // 1-indexed
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        AL[u].push_back(v);
    }
    for (int i = 0; i < l; i++) {
        int knocked; cin >> knocked;
        knocked--;
        dfs(knocked);
    }
    int ans = 0;
    for (auto b: visited) if (b) ans++;
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}