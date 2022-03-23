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

namespace primes {
    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef map<int, int> mii;

    ll _sieve_size;
    bitset<10000010> bs;                             // 10^7 is the rough limit
    vll p;                                           // compact list of primes

    void sieve(ll upperbound) {                      // range = [0..upperbound]
        _sieve_size = upperbound+1;                    // to include upperbound
        bs.set();                                      // all 1s
        bs[0] = bs[1] = 0;                             // except index 0+1
        for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
            // cross out multiples of i starting from i*i
            for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
            p.push_back(i);                              // add prime i to the list
        }
    }

    bool isPrime(ll N) {                             // good enough prime test
        if (N < _sieve_size) return bs[N];             // O(1) for small primes
        for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
            if (N%p[i] == 0)
            return false;
        return true;                                   // slow if N = large prime
    } // note: only guaranteed to work for N <= (last prime in vll p)^2

    // second part

    vll primeFactors(ll N) {                         // pre-condition, N >= 1
        vll factors;
        for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
            while (N%p[i] == 0) {                        // found a prime for N
            N /= p[i];                                 // remove it from N
            factors.push_back(p[i]);
            }
        if (N != 1) factors.push_back(N);              // remaining N is a prime
        return factors;
    }

    // third part

    int numPF(ll N) {
        int ans = 0;
        for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
            while (N%p[i] == 0) { N /= p[i]; ++ans; }
        return ans + (N != 1);
    }

    int numDiffPF(ll N) {
        int ans = 0;
        for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i) {
            if (N%p[i] == 0) ++ans;                      // count this prime factor
            while (N%p[i] == 0) N /= p[i];               // only once
        }
        if (N != 1) ++ans;
        return ans;
    }

    ll sumPF(ll N) {
        ll ans = 0;
        for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i)
            while (N%p[i] == 0) { N /= p[i]; ans += p[i]; }
        if (N != 1) ans += N;
        return ans;
    }

    int numDiv(ll N) {
        int ans = 1;                                   // start from ans = 1
        for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
            int power = 0;                               // count the power
            while (N%p[i] == 0) { N /= p[i]; ++power; }
            ans *= power+1;                              // follow the formula
        }
        return (N != 1) ? 2*ans : ans;                 // last factor = N^1
    }

    ll sumDiv(ll N) {
        ll ans = 1;                                    // start from ans = 1
        for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
            ll multiplier = p[i], total = 1;
            while (N%p[i] == 0) {
            N /= p[i];
            total += multiplier;
            multiplier *= p[i];
            }                                            // total for
            ans *= total;                                // this prime factor
        }
        if (N != 1) ans *= (N+1);                      // N^2-1/N-1 = N+1
        return ans;
    }

    ll EulerPhi(ll N) {
        ll ans = N;                                    // start from ans = N
        for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
            if (N%p[i] == 0) ans -= ans/p[i];            // count unique
            while (N%p[i] == 0) N /= p[i];               // prime factor
        }
        if (N != 1) ans -= ans/N;                      // last factor
        return ans;
    }
}

const int MAX_N = 10000 + 10;

int K, N;
vector<ll> numTerms;
vector<ll> memo;

void solve() {
    cin >> K >> N;
    numTerms.assign(N+1, 0);

    for (int i = 1; i <= N; i++) numTerms[i] = numTerms[i-1] + memo[i];
    for (int i = 1; i <= N; i++) numTerms[i]++;
    // debug(numTerms);

    ll numer = 3*numTerms[N]-4;
    cout << K << " ";
    if (numer % 2 == 0) cout << numer/2 << endl;
    else cout << numer << "/" << 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // precomputation
    primes::sieve(20000);
    memo.resize(MAX_N);
    for (int i = 1; i <= MAX_N; i++) memo[i] = primes::EulerPhi(i);

    // solve
    int t; cin >> t;
    while (t--) solve();
}