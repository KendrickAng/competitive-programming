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
using dii = tuple<double, int, int>;

int N, M, P;
vector<ii> judges;
vector<ii> tars;
vector<ii> feathers;

vector<bool> tarOk;
vector<bool> judgeOk;
vector<bool> featherOk;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void solve() {
    cin >> N >> M >> P;
    judges.resize(N);
    tars.resize(M);
    feathers.resize(P);

    // read input
    for (int i = 0; i < N; i++) cin >> judges[i].first >> judges[i].second;
    for (int i = 0; i < M; i++) cin >> tars[i].first >> tars[i].second;
    for (int i = 0; i < P; i++) cin >> feathers[i].first >> feathers[i].second;

    // greedy solve for judges and tars
    priority_queue<dii, vector<dii>, greater<dii>> pqt;
    priority_queue<dii, vector<dii>, greater<dii>> pqf;
    for (int i = 0; i < N; i++) {
        auto &[jx, jy] = judges[i];
        for (int j = 0; j < M; j++) {
            auto &[tx, ty] = tars[j];
            // debug(jx, jy, tx, ty, dist);
            pqt.push({distance(jx, jy, tx, ty), i, j});
        }
        for (int j = 0; j < P; j++) {
            auto &[fx, fy] = feathers[j];
            pqf.push({distance(jx, jy, fx, fy), i, j});
        }
    }

    tarOk.assign(M, true);
    judgeOk.assign(N, true);
    double tarsAns = 0.0;
    while (!pqt.empty()) {
        auto [dt, jid, tid] = pqt.top(); pqt.pop();
        // debug(dist, jid, tid);
        if (tarOk[tid] && judgeOk[jid]) {
            tarOk[tid] = false;
            judgeOk[jid] = false;
            tarsAns += dt;
        }
    }

    featherOk.assign(P, true);
    judgeOk.assign(N, true);
    double feathersAns = 0.0;

    while (!pqf.empty()) {
        auto [df, jid, fid] = pqf.top(); pqf.pop();
        // debug(dist, jid, fid);
        if (featherOk[fid] && judgeOk[jid]) {
            featherOk[fid] = false;
            judgeOk[jid] = false;
            feathersAns += df;
        }
    }

    // debug(tarsAns, feathersAns);

    // calculate final ans
    cout << fixed << setprecision(10);
    cout << tarsAns + feathersAns << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}