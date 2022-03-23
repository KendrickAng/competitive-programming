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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) : 
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), 
    found(N), dist(N), pi(N), width(N), dad(N) {}
  
  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }
  
  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;
    
    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};


using ll = long long;
using ii = pair<int, int>;

int N, M, S;
vector<int> living;
vector<int> shelters;
vector<int> shelterCap;
vector<vector<ii>> adjList;
vector<vector<ll>> shelterToLoc; // time needed

const ll INF2 = 1e18;

void solve() {
    cin >> N >> M >> S;
    living.resize(N);
    shelterCap.assign(N, 0);
    adjList.assign(N, {});
    shelterToLoc.assign(S, {});

    // read input
    for (int i = 0; i < N; i++) cin >> living[i];
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--; // locations given 1-indexed
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }
    for (int i = 0; i < S; i++) {
        int s, cap; cin >> s >> cap;
        s--; // shelters given 1-indexed
        shelters.push_back(s);
        shelterCap[s] = cap;
    }

    // find shortest path from each shelter to all locations
    for (int s = 0; s < S; s++) {
        // initialize stuff
        vector<ll> dist(N, INF2);
        dist[s] = 0;
        set<pair<ll, int>> pq;
        for (int u = 0; u < N; u++) pq.emplace(dist[u], u);

        // take pairs by non-decreasing order from s
        while (!pq.empty()) {
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());
            for (auto &[v, w]: adjList[u]) {
                if (dist[u] + v >= dist[v]) continue;
                pq.erase(pq.find({dist[v], v}));
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }

        // copy over distances
        shelterToLoc[s] = vector<ll>(dist.begin(), dist.end());
    }

    // min cost max flow
    int V = S + N + 2;
    int START = V-1;
    int END = V-2;
    MinCostMaxFlow mf(V);
    debug(START, END);

    // shelters: [0, S)
    // locations: [S, S+N)
    // source to shelters - cost = 0, cap = shelter cap
    for (int i = 0; i < S; i++) {
        mf.AddEdge(START, i, shelterCap[i], 0);
        debug(START, i, shelterCap[i]);
        
        // shelters to locations - cost = time, cap = infinite
        for (int j = 0; j < N; j++) {
            int lid = j + S;
            ll time = shelterToLoc[i][j];
            mf.AddEdge(i, lid, INF2, time);
            debug(i, lid, INF2, time);
        }
    }

    // locations to end - cost = 0, cap = population
    for (int i = 0; i < N; i++) {
        int lid = S+i;
        mf.AddEdge(lid, END, living[i], 0);
        debug(lid, END, living[i]);
    }

    auto [flow, cost] = mf.GetMaxFlow(START, END);
    cout << flow << " " << cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}