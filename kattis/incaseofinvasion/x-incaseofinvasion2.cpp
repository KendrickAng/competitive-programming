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

struct edge
{
	long long from, to, cap, flow, index;
	edge(long long from, long long to, long long cap, long long flow, long long index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct pairHash {
    size_t operator()(const pair<long long, long long>& pr) const {
        return ((size_t) pr.first + 1e6) * 1e8 + ((size_t) pr.second + 1e6);
    }
};

struct PushRelabel
{
	long long n;
    vector<edge> edgeList;
	vector<vector<long long>> g;
	vector<long long> excess;
	vector<long long> height, active, count;
	queue<long long> Q;

    long long S;
    long long T;
    unordered_map<pair<long long, long long>, int, pairHash> edgeMap;

	PushRelabel(long long n):
		n(n), g(n), excess(n), height(n), active(n), count(2*n) {}

	void addEdge(long long from, long long to, long long cap)
	{
        edgeList.emplace_back(from, to, cap, 0, g[to].size());
		g[from].push_back(edgeList.size()-1);
        edgeMap[{from,to}] = edgeList.size()-1;
		if(from==to) edgeList[g[from].back()].index++;
        edgeList.emplace_back(to, from, 0, 0, g[from].size()-1);
		g[to].push_back(edgeList.size()-1);
	}

	void enqueue(long long v)
	{
		if(!active[v] && excess[v] > 0)
		{
			active[v]=true;
			Q.push(v);
		}
	}

	void push(edge &e) {
		long long amt=min(excess[e.from], e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0)
			return;
		e.flow += amt;
		edgeList[g[e.to][e.index]].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);
	}

	void relabel(long long v) {
		count[height[v]]--;
		long long d=2*n;
		for(auto &tmp: g[v]) {
            auto &it = edgeList[tmp];
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]+1);
		}
		height[v]=d;
		count[height[v]]++;
		enqueue(v);
	}

	void gap(long long k) {
		for(long long v=0;v<n;v++) {
			if(height[v]<k) continue;
			count[height[v]]--;
			height[v]=max(height[v], n+1);
			count[height[v]]++;
			enqueue(v);
		}
	}

	void discharge(long long v) {
		for(long long i=0; excess[v]>0 && i<g[v].size(); i++) push(edgeList[g[v][i]]);
		if(excess[v]>0) {
			if(count[height[v]]==1)
				gap(height[v]);
			else
				relabel(v);
		}
	}

	long long max_flow(long long source, long long dest)
	{
        S = source;
        T = dest;
		count[0] = n-1;
		count[n] = 1;
		height[source] = n;
		active[source] = active[dest] = 1;
		for(auto &tmp:g[source]) {
            auto &it = edgeList[tmp];
			excess[source]+=it.cap;
			push(it);
		}

		while(!Q.empty())
		{
			long long v=Q.front();
			Q.pop();
			active[v]=false;
			discharge(v);
		}

		long long max_flow=0;
		for(auto &tmp:g[source]) {
            auto &e = edgeList[tmp];
			max_flow+=e.flow;
        }

		return max_flow;
	}

    edge &getEdge(int u, int v) {
        if (!hasEdge(u, v)) throw "no such edge!";
        return edgeList[edgeMap[{u,v}]];
    }

    bool hasEdge(int u, int v) {
        return edgeMap.find({u,v}) != edgeMap.end();
    }

    void setEdgeCap(int u, int v, long long newCap) {
        edge &e = getEdge(u, v);
        e.cap = newCap;
    }

    void reset() {
        height.assign(n, 0);
        active.assign(n, 0);
        count.assign(2*n, 0);
        excess.assign(n, 0);
        while (!Q.empty()) Q.pop();
        for (int i = 0; i < n; i++) {
            for (int eIdx: g[i]) {
                edge &e = edgeList[eIdx]; e.flow = 0;
            }
        }
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int eIdx: g[i]) {
                edge &e = edgeList[eIdx];
                if (e.cap > 0) {
                    string a = e.from == S ? "S" : 
                                e.from == T ? "T": to_string(e.from);
                    string b = e.to == S ? "S" :
                                e.to == T ? "T": to_string(e.to);
                    cout << a << "->" << b << " flow: " << e.flow << " cap: " << e.cap << endl;
                }
            }
        }
        cout << endl;
    }
};

using ll = long long;
using ii = pair<int, int>;

int N, M, S;
int V, START, END;
ll people = 0;
vector<int> living;
vector<int> shelters;
vector<int> shelterCap;
vector<vector<ii>> adjList;
vector<vector<ll>> shelterToLoc; // time needed
PushRelabel pr(0);

const ll INF2 = 1e18;

bool isOk(ll givenTime) {
    for (int i = 0; i < S; i++) {
        // shelters to locations
        for (int j = 0; j < N; j++) {
            int lid = j + S;
            ll needTime = shelterToLoc[i][j];
            pr.setEdgeCap(i, lid, (givenTime >= needTime) ? INF2 : 0);
        }
    }

    ll flow = pr.max_flow(START, END);
    pr.reset();
    // debug(flow, people, START, END);

    return flow == people;
}

void solve() {
    cin >> N >> M >> S;
    shelters.resize(S); // index to shelter index
    living.resize(N);
    shelterCap.assign(N, 0);
    adjList.assign(N, {});
    shelterToLoc.assign(S, vector<ll>(N, -1));

    // read input
    for (int i = 0; i < N; i++) {
        cin >> living[i];
        people += living[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--; // locations given 1-indexed
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }
    for (int i = 0; i < S; i++) {
        int shelterIdx, cap; cin >> shelterIdx >> cap;
        shelterIdx--; // shelters given 1-indexed
        shelters[i] = shelterIdx;
        shelterCap[shelterIdx] = cap;
        // debug(i, shelters[i]);
    }

    // find shortest path from each shelter to all locations
    for (int i = 0; i < S; i++) {
        int s = shelters[i];

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
        for (int j = 0; j < N; j++) {
            shelterToLoc[i][j] = dist[j];
        }
    }

    // min cost max flow
    V = S + N + 2;
    START = V-1;
    END = V-2;
    pr = PushRelabel(V);
    
    // shelters: [0, S)
    // locations: [S, S+N)
    // source to shelters
    for (int i = 0; i < S; i++) {
        pr.addEdge(START, i, shelterCap[shelters[i]]);

        // shelters to locations
        for (int j = 0; j < N; j++) {
            int lid = j + S;
            ll needTime = shelterToLoc[i][j];
            pr.addEdge(i, lid, 0); // change later
        }
    }

    // locations to end
    for (int i = 0; i < N; i++) {
        int lid = i + S;
        pr.addEdge(lid, END, living[i]);
    }

    ll lo = 0;
    ll hi = 1e14;
    ll last = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        // debug(lo, mid, hi);
        if (isOk(mid)) { // try a lower time
            hi = mid-1;
            last = mid;
        } else { // need more time
            lo = mid+1;
        }
    }

    cout << last << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}