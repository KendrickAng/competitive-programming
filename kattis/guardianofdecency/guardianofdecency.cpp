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

int MAX_N = 1010;

int N;
vector<int> height;
vector<char> gender;
vector<string> music;
vector<string> sport;

vector<vector<int>> adjList;
vector<int> visited;
vector<int> match;

int Aug(int u, int round) {
    if (visited[u] == round) return 0;
    visited[u] = round;
    for (auto &v: adjList[u]) {
        if (match[v] == -1 || Aug(match[v], round)) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> N;
    height.resize(N);
    gender.resize(N);
    music.resize(N);
    sport.resize(N);
    adjList.assign(N, vector<int>());

    // read input
    int males = 0;
    for (int i = 0; i < N; i++) {
        cin >> height[i] >> gender[i] >> music[i] >> sport[i];
        if (gender[i] == 'M') males++;
    }

    // form bipartite graph
    vector<int> mMap(N, -1);
    vector<int> fMap(N, -1);
    int midx = 0; // males (left set) start from 0
    int fidx = males; // females (right set) start from males count
    for (int i = 0; i < N; i++) { // males
        for (int j = 0; j < N; j++) { // females
            if (gender[i] == 'M' and gender[j] == 'F' and
                    abs(height[i] - height[j]) <= 40 and
                    music[i] == music[j] and
                    sport[i] != sport[j]) {
                if (mMap[i] == -1) mMap[i] = midx++;
                if (fMap[j] == -1) fMap[j] = fidx++;
                adjList[mMap[i]].push_back(fMap[j]);
            }
        }
    }

    // konig's theorem
    int MCBM = 0;
    match.assign(N, -1);
    visited.assign(midx, -1);
    for (int male = 0; male < midx; male++) {
        MCBM += Aug(male, male);
    }

    cout << N - MCBM << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}