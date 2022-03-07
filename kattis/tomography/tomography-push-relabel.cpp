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

// Adjacency list implementation of FIFO push relabel maximum flow
// with the gap relabeling heuristic.  This implementation is
// significantly faster than straight Ford-Fulkerson.  It solves
// random problems with 10000 vertices and 1000000 edges in a few
// seconds, though it is possible to construct test cases that
// achieve the worst-case.
//
// Running time:
//     O(|V|^3)
//
// INPUT: 
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual flow values, look at all edges with
//       capacity > 0 (zero capacity edges are residual edges).

//Push-Relabel Algorithm for Flows - Gap Heuristic, Complexity: O(V^3)
//To obtain the actual flow values, look at all edges with capacity > 0
//Zero capacity edges are residual edges

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
	vector<vector<ll> > g;
	vector<long long> excess;
	vector<long long> height, active, count;
	queue<long long> Q;

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

    void print() {
        for (int i = 0; i < n; i++) {
            for (int eIdx: g[i]) {
                edge &e = edgeList[eIdx];
                if (e.cap > 0) {
                    cout << e.from << "->" << e.to << " flow: " << e.flow << " cap: " << e.cap << endl;
                }
            }
        }
    }
};

int R, C;

int getRIdx(int r) {
    return r;
}

int getCIdx(int c) {
    return c + R;
}

void solve() {
    cin >> R >> C;
    int V = R + C + 2;
    int S = V-1;
    int T = V-2;
    // [0, R): rows
    // [R, R+C): cols
    PushRelabel mf(V);
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            mf.addEdge(getRIdx(r), getCIdx(c), 1);
        }
    }
    // read row capacities
    vector<ll> rows(R);
    for (int i = 0; i < R; i++) {
        int tmp; cin >> tmp;
        rows[i] = tmp;
        mf.addEdge(S, getRIdx(i), tmp);
    }
    // read col capacities
    vector<ll> cols(C);
    for (int i = 0; i < C; i++) {
        int tmp; cin >> tmp;
        cols[i] = tmp;
        mf.addEdge(getCIdx(i), T, tmp);
    }

    mf.max_flow(S, T);
    for (int r = 0; r < R; r++) {
        ll tmp = mf.getEdge(S, getRIdx(r)).flow;
        // debug(tmp);
        if (tmp != rows[r]) {
            cout << "No" << endl;
            return;
        }
    }
    for (int c = 0; c < C; c++) {
        ll tmp = mf.getEdge(getCIdx(c), T).flow;
        // debug(tmp);
        if (tmp != cols[c]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}