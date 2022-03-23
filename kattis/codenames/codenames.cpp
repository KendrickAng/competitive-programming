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

int N;
vector<string> words;
vector<vector<int>> adjList;
vector<int> color;

vector<int> match;
vector<int> vis;

int Aug(int L) {
  if (vis[L]) return 0;                          // L visited, return 0
  vis[L] = 1;
  for (auto &R : adjList[L])
    if ((match[R] == -1) || Aug(match[R])) {
      match[R] = L;                              // flip status
      return 1;                                  // found 1 matching
    }
  return 0;                                      // no matching
}

bool swapFree(int i, int j) {
    int diff = 0;
    string &a = words[i];
    string &b = words[j];
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
    }
    return diff != 2;
}

void solve() {
    cin >> N;
    words.resize(N);
    adjList.assign(N, {});
    color.assign(N, -1);
    match.assign(N, -1);

    // read input
    for (int i = 0; i < N; i++) cin >> words[i];

    // form the graph
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (!swapFree(i, j)) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    // split into bipartite sets
    for (int i = 0; i < color.size(); i++) {
        if (color[i] != -1) continue;
        int s = i;
        color[s] = 0;
        queue<int> q; q.push(s);
        bool isBipartite = true;
        while (!q.empty() and isBipartite) {
            int u = q.front(); q.pop();
            for (int &v: adjList[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    debug(u, v, words[u], words[v]);
                    isBipartite = false;
                    break;
                }
            }
        }
        assert(isBipartite);
    }

    // debug(color);
    // debug(adjList);

    unordered_set<int> freeV;
    for (int i = 0; i < color.size(); i++) {
        if (color[i] == 0) freeV.insert(i);
    }
    int MCBM = 0;
    for (auto &f: freeV) {
        vis.assign(N, 0);
        MCBM += Aug(f);
    }

    cout << N-MCBM << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}