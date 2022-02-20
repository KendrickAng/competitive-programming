#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

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

int N, K, M;
unordered_map<string, vector<int>> itemToStores;
vector<string> buyOrder;

void solve() {
    cin >> N >> K;

    // read items in shops
    for (int i = 0; i < K; i++) {
        int store;
        string item;
        cin >> store >> item;
        itemToStores[item].push_back(store);
    }

    // sort
    for (auto &[key, val]: itemToStores) {
        sort(val.begin(), val.end());
    }

    // cout << "ITEMS TO STORES" << endl;
    // for (auto [a, b]: itemToStores) {
    //     debug(a, b);
    // }

    // read order of items
    cin >> M;
    buyOrder.resize(M);
    for (int i = 0; i < M; i++) cin >> buyOrder[i];
    // debug(buyOrder);

    // forward to back
    vector<int> forward;
    string firstItem = buyOrder[0];
    forward.push_back(itemToStores[firstItem].front());
    for (int i = 1; i < buyOrder.size(); i++) {
        // debug(forward);
        string currItem = buyOrder[i];
        vector<int> &search = itemToStores[currItem];
        int prevStore = forward.back();
        int idx = lower_bound(search.begin(), search.end(), prevStore) - search.begin();
        if (idx == search.size()) {
            cout << "impossible" << endl;
            return;
        } else {
            forward.push_back(search[idx]);
        }
    }

    // back to forward
    vector<int> backward;
    string lastItem = buyOrder[M-1];
    backward.push_back(itemToStores[lastItem].back());
    for (int i = M-2; i >= 0; i--) {
        string currItem = buyOrder[i];
        vector<int> &search = itemToStores[currItem];
        int nextStore = backward.back();
        int idx = upper_bound(search.begin(), search.end(), nextStore) - search.begin() - 1;
        if (idx < 0) {
            cout << "impossible" << endl;
            return;
        } else {
            backward.push_back(search[idx]);
        }
    }
    reverse(backward.begin(), backward.end());

    // cout << forward.size() << endl;
    // debug(forward);
    // debug(backward);

    if (forward == backward) {
        cout << "unique" << endl;
    } else {
        cout << "ambiguous" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}