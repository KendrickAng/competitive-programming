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

void countingSort(vector<int> &SA, vector<int> &RA, int n, int k) {
    int maxi = max(300, n); // up to 255 ASCII chars
    vector<int> c(maxi, 0);

    // count frequency of each integer rank
    for (int i = 0; i < n; i++) c[i+k<n ? RA[i+k] : 0]++;
    for (int i = 0, sum = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }

    vector<int> tempSA(n);
    for (int i = 0; i < n; i++) tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    swap(SA, tempSA);
}

void constructSA(string &T) {
    int n = T.size() * 2 + 1;
    T = T + T;
    T += '\0';
    vector<int> SA; SA.resize(n);
    iota(SA.begin(), SA.end(), 0);

    // create initial ranking
    vector<int> RA; RA.resize(n); // rank array
    for (int i = 0; i < n; i++) RA[i] = T[i];

    // perform prefix doubling sort, repeat log_2(n) times
    for (int k = 1; k < n; k <<= 1) {
        countingSort(SA, RA, n, k); // sort by 2nd item first
        countingSort(SA, RA, n, 0); // then sort by 1st item, for stable sort

        // perform re-ranking
        vector<int> tempRA(n);
        int r = 0;
        tempRA[SA[0]] = r;
        for (int i = 1; i < n; i++) {
            // same pair -> same rank r, otherwise increase r
            tempRA[SA[i]] = ((RA[SA[i]] == RA[SA[i-1]]) && (RA[SA[i]+k] == RA[SA[i-1]+k]))
                ? r 
                : ++r;
        }
        swap(RA, tempRA);
        if (RA[SA[n-1]] == n-1) break;
    }

    for (int i = 0; i < n; i++) {
        if (SA[i] < n/2) cout << T[SA[i]+n/2-1];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while (getline(cin, s)) {
        constructSA(s);
    }
}