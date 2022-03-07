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
	ll from, to, cap, flow, index;
	edge(ll from, ll to, ll cap, ll flow, ll index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
	ll n;
	vector<vector<edge> > g;
	vector<ll> excess;
	vector<ll> height, active, count;
	queue<ll> Q;

	PushRelabel(ll n):
		n(n), g(n), excess(n), height(n), active(n), count(2*n) {}

	void addEdge(ll from, ll to, ll cap)
	{
		g[from].push_back(edge(from, to, cap, 0, g[to].size()));
		if(from==to)
			g[from].back().index++;
		g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
	}

	void enqueue(ll v)
	{
		if(!active[v] && excess[v] > 0)
		{
			active[v]=true;
			Q.push(v);
		}
	}

	void push(edge &e)
	{
		ll amt=min(excess[e.from], e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0)
			return;
		e.flow += amt;
		g[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);
	}

	void relabel(ll v)
	{
		count[height[v]]--;
		ll d=2*n;
		for(auto &it:g[v])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]+1);
		}
		height[v]=d;
		count[height[v]]++;
		enqueue(v);
	}

	void gap(ll k)
	{
		for(ll v=0;v<n;v++)
		{
			if(height[v]<k)
				continue;
			count[height[v]]--;
			height[v]=max(height[v], n+1);
			count[height[v]]++;
			enqueue(v);
		}
	}

	void discharge(ll v)
	{
		for(ll i=0; excess[v]>0 && i<g[v].size(); i++)
			push(g[v][i]);
		if(excess[v]>0)
		{
			if(count[height[v]]==1)
				gap(height[v]);
			else
				relabel(v);
		}
	}

	ll max_flow(ll source, ll dest)
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
			ll v=Q.front();
			Q.pop();
			active[v]=false;
			discharge(v);
		}

		ll max_flow=0;
		for(auto &e:g[source])
			max_flow+=e.flow;

		return max_flow;
	}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M, S, T; cin >> N >> M >> S >> T;

    PushRelabel pr(N);
    for (int i = 0; i < M; i++) {
        ll u, v, cap; cin >> u >> v >> cap;
        pr.addEdge(u, v, cap);
    }

    ll mf = pr.max_flow(S, T);

    // get max flow edges
    vector<edge> maxFlowEdges;
    for (int i = 0; i < N; i++) {
        for (edge &e: pr.g[i]) {
            // cout << e.from << " " << e.to << " " << e.flow << " " << e.cap << endl;
            if (e.flow > 0 and e.cap > 0) maxFlowEdges.push_back(e);
        }
    }
    ll mPrime = maxFlowEdges.size();

    // print answer
    cout << N << " " << mf << " " << mPrime << endl;
    for (edge &e: maxFlowEdges) {
        cout << e.from << " " << e.to << " " << e.flow << endl;
    }
}