#include <bits/stdc++.h>

using namespace std;

using ii = pair<long long, long long>;

const int MAX_N = 300010;

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
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        T[i] = s[i];
    }
    n = s.size();

    // prepare rabin karp stuff
    computeRollingHash();

    // answer queries
    int N; cin >> N;
    while (N--) {
        int l, r; cin >> l >> r;
        cout << hash_fast(l, r-1) << endl;
    }
}