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

#define LSOne(S) ((S) & -(S)) // the key operation

#define LSOne(S) ((S) & -(S)) // the key operation

class FenwickTree { // index 0 is not used
public:
  vector<int> ft; // internal FT is an array
  void build(const vector<int> &f) {
    int m = (int)f.size() - 1; // note f[0] is always 0
    ft.assign(m + 1, 0);
    for (int i = 1; i <= m; ++i) { // O(m)
      ft[i] += f[i];               // add this value
      if (i + LSOne(i) <= m)       // i has parent
        ft[i + LSOne(i)] += ft[i]; // add to that parent
    }
  }

  int select(int k) { // find the first index that sum(1...index) >= k; return
                      // ft.size() if can't find any;
    int p = 1;
    while (p * 2 < (int)ft.size())
      p *= 2;
    int i = 0;
    while (p && i + p < ft.size()) {
      if (k > ft[i + p]) {
        k -= ft[i + p];
        i += p;
      }
      p /= 2;
    }
    return i + 1;
  }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> a(10, 0);
    FenwickTree ft;
    ft.build(a);
}