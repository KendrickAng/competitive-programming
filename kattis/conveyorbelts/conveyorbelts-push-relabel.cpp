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

//Push-Relabel Algorithm for Flows - Gap Heuristic, Complexity: O(V^3)
//To obtain the actual flow values, look at all edges with capacity > 0
//Zero capacity edges are residual edges

struct edge
{
	long long from, to, cap, flow, index;
	edge(long long from, long long to, long long cap, long long flow, long long index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
	long long n;
	vector<vector<edge> > g;
	vector<long long> excess;
	vector<long long> height, active, count;
	queue<long long> Q;

	PushRelabel(long long n):
		n(n), g(n), excess(n), height(n), active(n), count(2*n) {}

	void addEdge(long long from, long long to, long long cap)
	{
		g[from].push_back(edge(from, to, cap, 0, g[to].size()));
		if(from==to)
			g[from].back().index++;
		g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
	}

	void enqueue(long long v)
	{
		if(!active[v] && excess[v] > 0)
		{
			active[v]=true;
			Q.push(v);
		}
	}

	void push(edge &e)
	{
		long long amt=min(excess[e.from], e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0)
			return;
		e.flow += amt;
		g[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);
	}

	void relabel(long long v)
	{
		count[height[v]]--;
		long long d=2*n;
		for(auto &it:g[v])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]+1);
		}
		height[v]=d;
		count[height[v]]++;
		enqueue(v);
	}

	void gap(long long k)
	{
		for(long long v=0;v<n;v++)
		{
			if(height[v]<k)
				continue;
			count[height[v]]--;
			height[v]=max(height[v], n+1);
			count[height[v]]++;
			enqueue(v);
		}
	}

	void discharge(long long v)
	{
		for(long long i=0; excess[v]>0 && i<g[v].size(); i++)
			push(g[v][i]);
		if(excess[v]>0)
		{
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
		for(auto &it:g[source])
		{
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
		for(auto &e:g[source])
			max_flow+=e.flow;

		return max_flow;
	}

    void print() {
        for (int i = 0; i < n; i++) {
            for (edge &e: g[i]) {
                if (e.cap > 0) {
                    cout << e.from << "->" << e.to << " flow: " << e.flow << " cap: " << e.cap << endl;
                }
            }
        }
    }
};

int N, K, M;
const ll INF = 1e18;

// n is 1-indexed, k is 0-indexed
ll node(int n, int k) {
    return ((n-1)*K) + k;
}

void solve() {
    cin >> N >> K >> M;
    ll V = N * K + 2;
    ll S = V - 1;
    ll T = V - 2;
    
    PushRelabel pr(V);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        // connect all nodes of u to all nodes of v
        for (int j = 0; j < K; j++) {
            ll uu = node(u, j);
            ll vv = node(v, (j+1) % K);
            pr.addEdge(uu, vv, 1);
        }
    }
    // connect source to all producer nodes
    for (int i = 0; i < K; i++) {
        pr.addEdge(S, node(i+1, i), 1);
    }
    // connect final junction N to sink
    for (int i = 0; i < K; i++) {
        pr.addEdge(node(N, i), T, INF);
    }

    cout << pr.max_flow(S, T) << endl;
    // debug(S, T);
    // pr.print();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}