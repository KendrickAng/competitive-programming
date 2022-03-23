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

using ull = unsigned long long;
using ll = long long;
using ii = pair<int, int>;

struct Product {
    ll initialCost;
    ll dailyProfit;
};

ll N, need;
vector<Product> products;

void printProducts() {
    for (Product &p: products) {
        cout << "[" << p.dailyProfit << "," << p.initialCost << "]" << " ";
    }
    cout << endl;
}

ll netProfit(Product &p, ll days) {
    return (p.dailyProfit * days) - p.initialCost;
}

bool isOk(ll days) {
    ll sofar = 0;
    for (int i = 0; i < N; i++) {
        ll net = netProfit(products[i], days);
        if (net > 0) {
            // return true if min threshold would be exceeded
            if (need - sofar <= net) return true;
            // otherwise, continue looking for more net profit
            sofar += net;
        }
    }
    return false;
}

void solve() {
    cin >> N >> need;
    products.resize(N);

    // read input
    for (int i = 0; i < N; i++) cin >> products[i].dailyProfit;
    for (int i = 0; i < N; i++) cin >> products[i].initialCost;

    ll lo = 0;
    ll hi = 5e18;
    ll lastAns = -1;
    while (lo <= hi) {
        // or use unsigned long long
        // ll mid = ((ull) lo + (ull) hi) / 2;
        ll mid = lo - ((lo-hi) / 2);
        // debug(mid);
        if (isOk(mid)) { // works, now try with less days
            hi = mid - 1;
            lastAns = mid;
        } else { // cannot, need more days
            lo = mid + 1;
        }
    }

    cout << lastAns << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    // TODO convert this later
    // int t; cin >> t;
    // while (t--) solve();
}