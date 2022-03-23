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

int N, R, C, SR, SC, TR, TC;
vector<vector<ll>> dist;

vector<int> rOff = {0, 0, -1, 1};
vector<int> cOff = {1, -1, 0, 0};

void solve() {
    cin >> N >> C >> R >> SC >> SR >> TC >> TR;
    dist.assign(R, vector<ll>(C, -1));

    // bfs from all bases - find shortest distance from any base to point
    queue<ii> q;
    for (int i = 0; i < N; i++) {
        int r, c; cin >> c >> r;
        dist[r][c] = 0;
        q.push({ r, c });
    }

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        // iterate neighbours
        for (int i = 0; i < 4; i++) {
            int rr = r + rOff[i];
            int cc = c + cOff[i];
            if (rr < 0 or rr >= R or cc < 0 or cc >= C) continue;
            if (dist[rr][cc] != -1) continue;
            dist[rr][cc] = dist[r][c] + 1;
            q.push({ rr, cc });
        }
    }

    // BSTA on min separation
    ll lo = 0;
    ll hi = min(dist[SR][SC], dist[TR][TC]);
    ll lastSep = -1;
    ll lastLen = -1;
    // debug(SR, SC, TR, TC);
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        // debug(lo, mid, hi);
        // calculate route length
        ll length = -1;
        queue<ii> q;
        vector<vector<ll>> dist2(R, vector<ll>(C, -1));
        dist2[SR][SC] = 0;
        q.push({ SR, SC });
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            // debug(mid, r, c, dist[r][c]);
            if (dist[r][c] < mid) continue;
            if (r == TR and c == TC) {
                length = dist2[r][c];
                break;
            }

            // iterate neighbours
            for (int i = 0; i < 4; i++) {
                int rr = r + rOff[i];
                int cc = c + cOff[i];
                if (rr < 0 or rr >= R or cc < 0 or cc >= C) continue;
                if (dist2[rr][cc] != -1) continue;
                dist2[rr][cc] = dist2[r][c] + 1;
                q.push({ rr, cc });
            }
        }

        if (length != -1) {
            lo = mid + 1;
            lastSep = mid;
            lastLen = length;
        } else {
            hi = mid - 1;
        }
    }

    cout << lastSep << " " << lastLen << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}