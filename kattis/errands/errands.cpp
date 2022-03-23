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

#define LSOne(S) ((S) & -(S))
using ll = long long;
using ii = pair<int, int>;

int N, S, T;
vector<vector<double>> memo;
vector<vector<ii>> nextState;
vector<vector<double>> dist;
vector<string> locations;
unordered_map<string, pair<double, double>> locToCoord;

vector<string> split(string &line) {
    stringstream ss(line);
    vector<string> ret;
    string token;
    while (ss >> token) {
        ret.push_back(token);
    }
    return ret;
}

double distance(pair<double,double> &p1, pair<double,double> &p2) {
    double xx = abs(p1.first - p2.first);
    double yy = abs(p1.second - p2.second);
    return sqrt(xx*xx + yy*yy);
}

double dp(int u, int mask) {
    // debug(u, mask, path);
    if (mask == 0) {
        return dist[u][T]; // last position is home
    }
    if (memo[u][mask] == -1.0) {
        double ans = numeric_limits<double>::max();
        int m = mask;
        while (m) {
            int two_pow_v = LSOne(m);
            int v = __builtin_ctz(two_pow_v) + 1;
            int vMask =  mask^two_pow_v;
            double temp = dist[u][v] + dp(v, vMask);
            if (temp < ans) {
                ans = temp;
                nextState[u][mask] = {v, vMask};
            }
            m -= two_pow_v;
        }
        memo[u][mask] = ans;
    }
    return memo[u][mask];
}

void solve() {
    cin >> N;
    locations.resize(N);

    // read input
    for (int i = 0; i < N; i++) {
        string s; double x, y; cin >> s >> x >> y;
        locToCoord[s] = {x, y};
        locations[i] = s;
    }

    // tsp
    cin.ignore();
    string line;
    while (getline(cin, line)) {
        // convert line into tokens
        vector<string> tokens(split(line));

        // build auxillary data structures
        vector<string> idxToToken(tokens.size() + 2);
        idxToToken[0] = "work"; S = 0;
        int id = 1; // starting city always 0
        for (string &loc: tokens) {
            idxToToken[id++] = loc;
        }
        idxToToken[id] = "home"; T = id;

        dist.assign(tokens.size()+2, vector<double>(tokens.size()+2));
        for (int i = 0; i < tokens.size()+2; i++) {
            for (int j = 0; j < tokens.size()+2; j++) {
                string &s1 = idxToToken[i];
                string &s2 = idxToToken[j];
                dist[i][j] = distance(locToCoord[s1], locToCoord[s2]);
            }
        }

        // initialize memo table, etc
        int n = tokens.size();
        memo.assign(n+1, vector<double>((1 << n), -1.0));
        nextState.assign(n+1, vector<ii>((1 << n), {-1,-1}));
        double best = dp(0, (1 << n)-1);

        // recosntruct the path
        int u = 0;
        int mask = (1 << n)-1;
        while (u != -1 and mask != -1) {
            if (u != 0) cout << idxToToken[u] << " ";
            auto [v, vMask] = nextState[u][mask];
            u = v;
            mask = vMask;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}