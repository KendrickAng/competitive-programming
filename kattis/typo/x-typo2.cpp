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
using ull = unsigned long long;
using ii = pair<int, int>;

const ull P = 27;
const ull M = 2147483659ULL;
const ull MAX_LEN = 1000010;

int N;
vector<string> words;
vector<ull> power(MAX_LEN);
vector<ull> rollingHashes(MAX_LEN);
set<pair<int,ull>> hashes;

// compute rolling hash https://cp-algorithms.com/string/string-hashing.html
void computeHash(const string &s) {
    int n = s.size();
    power[0] = 1;
    for (int i = 1; i < n; i++) {
        power[i] = (power[i-1] * P) % M;
    }
    rollingHashes[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0) rollingHashes[i] = rollingHashes[i-1];
        rollingHashes[i] = (rollingHashes[i] + ((s[i]-'a'+1) * power[i]) % M) % M;
    }
}

long long extEuclid(long long a, long long b, long long &x, long long &y) {    // pass x and y by ref
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {                                    // repeats until b == 0
    long long q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

long long modInverse(long long b, long long m) {                   // returns b^(-1) (mod m)
  long long x, y;
  long long d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return (x+m)%m;                                // this is the answer
}

ull hash_fast(ull L, ull R) {
  if (L == 0) return rollingHashes[R];
  ull ans = 0;
  ans = ((rollingHashes[R] - rollingHashes[L-1]) % M + M) % M;
  ans = ((ll)ans * modInverse(power[L], M)) % M;   // remove P[L]^-1 (mod M)
  return ans;
}

ll fastpow(ll base, ll exp, ll mod) {
    base %= mod;
    exp %= mod;
    ll res = 1;
    while(exp > 0) {
        if((exp & 1) == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return res % mod;
}

bool typo(const string &s) {
    computeHash(s);
    int n = s.size();
    // break the string and recompute hash with that one char left out
    for (int i = 0; i < n; i++) {
        ull prefixHash = hash_fast(0, i);
        ull suffixHash = hash_fast(i+1, n-1);
        ull partialHash = (prefixHash + suffixHash) % M;
        string tmp = s.substr(0,i)+s.substr(i+1);
        debug(tmp, n-1, partialHash);
        if (hashes.find({n-1, partialHash}) != hashes.end()) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> N;
    words.reserve(N);

    // generate initial hashes of strings
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        words.push_back(s);
        computeHash(s);
        hashes.insert({s.size(), hash_fast(0, s.size()-1)});
        debug(hashes);
    }

    bool printed = false;
    for (string &s: words) {
        if (typo(s)) {
            cout << s << endl;
            printed = true;
        }
    }

    if (!printed) cout << "NO TYPOS" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}