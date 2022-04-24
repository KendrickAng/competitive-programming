#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll MOD = 998244353;

struct Mat {
  ll n, m;
  vector<vector<ll>> a;
  Mat() { }
  Mat(ll _n, ll _m) {n = _n; m = _m; a.assign(n, vector<ll>(m, 0)); }
  Mat(vector< vector<ll> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }
  inline void make_unit() {
    assert(n == m);
    for (int i = 0; i < n; i++)  {
      for (int j = 0; j < n; j++) a[i][j] = i == j;
    }
  }
  inline Mat operator + (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans.a[i][j] = (((a[i][j] + b.a[i][j]) % MOD) + MOD) % MOD;
      }
    }
    return ans;
  } 
  inline Mat operator - (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans.a[i][j] = (((a[i][j] - b.a[i][j] + MOD) % MOD) + MOD) % MOD;
      }
    }
    return ans;
  }
  inline Mat operator * (const Mat &b) {
    assert(m == b.n);
    Mat ans = Mat(n, b.m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < b.m; j++) {
        for(int k = 0; k < m; k++) {
          ans.a[i][j] = (((ans.a[i][j] + a[i][k] * b.a[k][j] % MOD) % MOD) + MOD) % MOD;
        }
      }
    }
    return ans;
  }
  inline Mat pow(long long k) {
    assert(n == m);
    Mat ans(n, n), t = a; ans.make_unit();
    while (k) {
      if (k & 1) ans = ans * t;
      t = t * t;
      k >>= 1;
    }
    return ans;
  }
  inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
  inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
  inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
  inline bool operator == (const Mat& b) { return a == b.a; }
  inline bool operator != (const Mat& b) { return a != b.a; }
};

int N;
vector<int> as; // coefficients
vector<int> xs; // values of x
Mat mat;
Mat vec;

ll query(ll T) {
    if (T < N) return xs[T] % MOD;
    Mat m = mat.pow(T-N+1);
    Mat v = m * vec;
    return v.a[1][0];
}

void solve() {
    cin >> N;
    as.resize(N+1);
    xs.resize(N);
    vec = Mat(N+1, 1);
    mat = Mat(N+1, N+1);

    // read input
    for (int i = 0; i < N+1; i++) {
        cin >> as[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> xs[i];
    }

    // form matrix
    mat.a[0][0] = 1;
    for (int i = 0; i < N+1; i++) mat.a[1][i] = as[i];
    for (int i = 2; i < N+1; i++) mat.a[i][i-1] = 1;

    // form vector
    vec.a[0][0] = 1;
    for (int i = 1; i < N+1; i++) vec.a[i][0] = xs[xs.size()-i];

    // answer queries
    ll Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll T; cin >> T >> MOD;
        cout << query(T) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}