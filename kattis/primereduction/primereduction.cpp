#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll _sieve_size;
bitset<10000010> bs;
vector<ll> p;

void sieve(ll n) {
    _sieve_size = n + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; i++) {
        if (bs[i]) {
            for (ll j = i*i; j < _sieve_size; j+=i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

bool isPrime(ll n) {
    if (n < _sieve_size) return bs[n];
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; i++) {
        if (n % p[i] == 0) {
            return false;
        }
    }
    return true;
}

ll primeFactorise(ll n) {
    ll ret = 0;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; i++) {
        while (n % p[i] == 0) {
            n /= p[i];
            ret += p[i];
        }
    }
    if (n != 1) ret += n;
    return ret;
}

void solve(ll n) {
    long times = 1;
    while (!isPrime(n)) {
        n = primeFactorise(n);
        times++;
    }
    cout << n << " " << times << endl;
}

int main() {
    sieve(10000000);

    int n;
    while (true) {
        cin >> n;
        if (n == 4) break;
        solve(n);
    }
}