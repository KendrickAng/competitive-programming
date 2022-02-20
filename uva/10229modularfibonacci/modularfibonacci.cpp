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

ll MOD;

const int MAX_N = 2;                             // 2x2 for Fib matrix

struct Matrix { ll mat[MAX_N][MAX_N]; };         // we return a 2D array

ll mod(ll a, ll m) { return ((a%m)+m) % m; }     // ensure positive answer

Matrix matMul(Matrix a, Matrix b) {              // normally O(n^3)
  Matrix ans;                                    // but O(1) as n = 2
  for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
      ans.mat[i][j] = 0;
  for (int i = 0; i < MAX_N; ++i)
    for (int k = 0; k < MAX_N; ++k) {
      if (a.mat[i][k] == 0) continue;            // optimization
      for (int j = 0; j < MAX_N; ++j) {
        ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
        ans.mat[i][j] = mod(ans.mat[i][j], MOD); // modular arithmetic
      }
    }
  return ans;
}

Matrix matPow(Matrix base, int p) {              // normally O(n^3 log p)
  Matrix ans;                                    // but O(log p) as n = 2
  for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
      ans.mat[i][j] = (i == j);                  // prepare identity matrix
  while (p) {                                    // iterative D&C version
    if (p&1)                                     // check if p is odd
      ans = matMul(ans, base);                   // update ans
    base = matMul(base, base);                   // square the base
    p >>= 1;                                     // divide p by 2
  }
  return ans;
}
void solve(ll n, ll m) {
    MOD = 1 << m;
    // fibnacci matrix
    Matrix fib;
    fib.mat[0][0] = 1;
    fib.mat[0][1] = 1;
    fib.mat[1][0] = 1;
    fib.mat[1][1] = 0;
    fib = matPow(fib, 11);

    // initial matrix
    ll initial[2][1];
    initial[0][0] = 1;
    initial[1][0] = 0;

    // get answer
    ll ans = 0;
    for (int k = 0; k < MAX_N; k++) {
        ans += fib.mat[1][k] * initial[k][0];
    }

    cout << fib.mat[0][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
}