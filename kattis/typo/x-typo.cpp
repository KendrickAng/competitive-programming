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

using ii = pair<long long, long long>;

const int MAX_N = 1000010;

// T = text, P = pattern
char T[MAX_N];                         
long long n, m;                                        // n = |T|, m = |P|

// Rabin-Karp's algorithm specific code
using ll = __int128_t;

const long long p = 131;                               // p and M are
const long long M = 1e18 + 9;                             // relatively prime

long long Pow[MAX_N];                                  // to store p^i % M
long long h[MAX_N];                                    // to store prefix hashes

void computeRollingHash() {                      // Overall: O(n)
  Pow[0] = 1;                                    // compute p^i % M
  for (int i = 1; i < n; ++i)                    // O(n)
    Pow[i] = ((ll)Pow[i-1]*p) % M;
  h[0] = 0;
  for (int i = 0; i < n; ++i) {                  // O(n)
    if (i != 0) h[i] = h[i-1];                   // rolling hash
    h[i] = (h[i] + ((ll)T[i]*Pow[i]) % M) % M;
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

unsigned long long hash_fast(long long L, long long R) {                    // O(1) hash of any substr
  if (L == 0) return h[R];                       // h is the prefix hashes
  long long ans = 0;
  ans = ((h[R] - h[L-1]) % M + M) % M;           // compute differences
  ans = ((ll)ans * modInverse(Pow[L], M)) % M;   // remove P[L]^-1 (mod M)
  return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // read input
    int N; cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) cin >> words[i];

    // hash words
    unordered_set<long long> dict;
    for (string &word: words) {
        n = word.size();
        for (int i = 0; i < n; i++) T[i] = word[i];
        computeRollingHash();
        long long wordHash = hash_fast(0, n-1);
        dict.insert(wordHash);
        debug(word, wordHash);
    }

    bool printed = false;
    for (int i = 0; i < N; i++) {
        string &word = words[i];
        n = word.size();
        for (int i = 0; i < n; i++) T[i] = word[i];
        computeRollingHash();
        long long fullHash = hash_fast(0, n-1);
        debug(word, fullHash);

        for (int j = 0; j < word.size(); j++) {
            cout << "deleting " << j << endl;
            long long partialHash = (fullHash - ((ll)T[j]*Pow[j] % M)) % M;
            debug(partialHash);
            if (dict.count(partialHash) > 0) {
                cout << word << endl;
                printed = true;
                break;
            }
        }
    }

    if (!printed) cout << "NO TYPOS" << endl;
}