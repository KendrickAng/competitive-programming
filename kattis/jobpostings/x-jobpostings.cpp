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
using tup = tuple<int,int,int>;

int N, M;

vector<int> vacancies;
vector<bool> hasJob;
vector<vector<int>> satMat = {
    {4, 3, 2, 1},
    {8, 7, 6, 5},
    {12, 11, 10, 9}
};

void solve() {
    vacancies.assign(N, 0);
    hasJob.assign(M, false);

    // read vacancies
    for (int i = 0; i < N; i++) {
        cin >> vacancies[i];
    }

    // read preferences
    priority_queue<tup> pq;
    for (int i = 0; i < M; i++) {
        int yr, c1, c2, c3, c4;
        cin >> yr >> c1 >> c2 >> c3 >> c4;
        yr--; // zero indexed year
        // debug(yr, c1, c2, c3, c4, i);
        pq.push({ satMat[yr][0], c1, i });
        pq.push({ satMat[yr][1], c2, i });
        pq.push({ satMat[yr][2], c3, i });
        pq.push({ satMat[yr][3], c4, i });
    }

    ll ans = 0;
    while (!pq.empty()) {
        auto [pts, jobId, sId] = pq.top(); pq.pop();
        if (hasJob[sId]) continue;
        if (vacancies[jobId] == 0) continue;
        
        ans += pts;
        vacancies[jobId]--;
        hasJob[sId] = true;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;
        solve();
    }
}