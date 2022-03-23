#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

using ll = long long;
using ii = pair<int, int>;

const int MAX_N = 1010;
const int MAX_CHILD = 2;

vector<vector<int>> adjList;
vector<vector<int>> children;
vector<bool> visited;
vector<vector<int>> memo(MAX_N, vector<int>(MAX_CHILD));

void dfs(int u) {
    visited[u] = true;
    for (auto &v: adjList[u]) {
        if (!visited[v]) {
            children[u].push_back(v);
            dfs(v);
        }
    }
}

// flag 1 -> u was taken, flag 0 -> u wasn't taken
int MVC(int u, int flag) {
    if (memo[u][flag] == -1) {
        int ans = -1;
        if (children[u].empty()) {
            ans = flag;
        } else if (flag == 0) {
            ans = 0;
            for (auto &v: children[u]) ans += MVC(v, 1);
        } else if (flag == 1) {
            ans = 1;
            for (auto &v: children[u]) ans += min(MVC(v, 1), MVC(v, 0));
        }
        memo[u][flag] = ans;
    }
    return memo[u][flag];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        adjList.assign(N, vector<int>());
        children.assign(N, vector<int>());
        // read adjlist
        for (int i = 0; i < N; i++) {
            int ni; cin >> ni;
            for (int j = 0; j < ni; j++) {
                int v; cin >> v; v--; // 0-based indexing
                adjList[i].push_back(v);
            }
        }
        if (N == 1) { // special case 
            cout << 1 << endl;
            continue;
        }

        visited.assign(N, false);
        dfs(0); // root the tree at vertex 0

        fill(memo.begin(), memo.end(), vector<int>(MAX_CHILD, -1)); // memset
        cout << min(MVC(0, 1), MVC(0, 0)) << endl;
    }
}