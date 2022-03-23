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

const int N = 2000;

/* Complexity: O(n^3) but optimized
It finds minimum cost maximum matching. For finding maximum cost maximum matching 
add -cost and return -matching(). 1-indexed 
Windows:
g++ program.cpp -Wl,--stack=268435456
Linux:
ulimit -s unlimited
g++ program.cpp
*/
struct Hungarian {
  long long c[N][N], fx[N], fy[N], d[N];
  int l[N], r[N], arg[N], trace[N];
  queue<int> q;
  int start, finish, n;
  const long long inf = 1e18;
  Hungarian() {}
  Hungarian(int n1, int n2): n(max(n1, n2)) {
    for (int i = 1; i <= n; ++i) {
      fy[i] = l[i] = r[i] = 0;
      for (int j = 1; j <= n; ++j) c[i][j] = inf;
    }
  }
  void add_edge(int u, int v, long long cost) {
    c[u][v] = min(c[u][v], cost);
  }
  inline long long getC(int u, int v) {
    return c[u][v] - fx[u] - fy[v];
  }
  void initBFS() {
    while (!q.empty()) q.pop();
    q.push(start);
    for (int i = 0; i <= n; ++i) trace[i] = 0;
    for (int v = 1; v <= n; ++v) {
      d[v] = getC(start, v);
      arg[v] = start;
    }
    finish = 0;
  }
  void findAugPath() {
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v = 1; v <= n; ++v) if (!trace[v]) {
          long long w = getC(u, v);
          if (!w) {
            trace[v] = u;
            if (!r[v]) {
              finish = v;
              return;
            }
            q.push(r[v]);
          }
          if (d[v] > w) {
            d[v] = w;
            arg[v] = u;
          }
        }
    }
  }
  void subX_addY() {
    long long delta = inf;
    for (int v = 1; v <= n; ++v) if (trace[v] == 0 && d[v] < delta) {
        delta = d[v];
      }
    // Rotate
    fx[start] += delta;
    for (int v = 1; v <= n; ++v) if(trace[v]) {
        int u = r[v];
        fy[v] -= delta;
        fx[u] += delta;
      } else d[v] -= delta;
    for (int v = 1; v <= n; ++v) if (!trace[v] && !d[v]) {
        trace[v] = arg[v];
        if (!r[v]) {
          finish = v;
          return;
        }
        q.push(r[v]);
      }
  }
  void Enlarge() {
    do {
      int u = trace[finish];
      int nxt = l[u];
      l[u] = finish;
      r[finish] = u;
      finish = nxt;
    } while (finish);
  }
  long long maximum_matching() {
    for (int u = 1; u <= n; ++u) {
      fx[u] = c[u][1];
      for (int v = 1; v <= n; ++v) {
        fx[u] = min(fx[u], c[u][v]);
      }
    }
    for (int v = 1; v <= n; ++v) {
      fy[v] = c[1][v] - fx[1];
      for (int u = 1; u <= n; ++u) {
        fy[v] = min(fy[v], c[u][v] - fx[u]);
      }
    }
    for (int u = 1; u <= n; ++u) {
      start = u;
      initBFS();
      while (!finish) {
        findAugPath();
        if (!finish) subX_addY();
      }
      Enlarge();
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (c[i][l[i]] != inf) ans += c[i][l[i]];
      else l[i] = 0;
    }
    return ans;
  }
};

using ll = long long;
using ii = pair<int, int>;

struct pt {
    ll x;
    ll y;
};

int n, m;
vector<pt> bottles;
vector<pt> couriers;
pt rst;

ll mhn(pt &a, pt &b) {
    return abs(b.x-a.x) + abs(b.y-a.y);
}

void solve() {
    cin >> n >> m;
    bottles.resize(n);
    couriers.resize(m);

    for (int i = 0; i < n; i++) cin >> bottles[i].x >> bottles[i].y;
    for (int i = 0; i < m; i++) cin >> couriers[i].x >> couriers[i].y;
    cin >> rst.x >> rst.y;

    // calculate bottle-courier costs
    Hungarian hun(n, n+m-1);
    for (int i = 0; i < n; i++) {
        // courier-bottle-restaurant
        for (int j = 0; j < m; j++) {
            hun.add_edge(i+1, j+1, mhn(couriers[j], bottles[i]) + mhn(bottles[i], rst));
        }
        // restaurant-bottle-restaurant
        for (int j = m; j < n+m-1; j++) {
            hun.add_edge(i+1, j+1, mhn(rst, bottles[i]) + mhn(bottles[i], rst));
        }
    }

    cout << hun.maximum_matching() << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}