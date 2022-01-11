#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bitset<10000000> bs;
ll _sieve_size;
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

void eulerPhi(ll n) {
    ll ans = n;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; i++) {
        if (n % p[i] == 0) ans -= ans/p[i];
        while (n % p[i] == 0) {
            n /= p[i];
        }
    }
    if (n != 1) ans -= ans/n;
    cout << ans << endl;
}

int main() {
    sieve(1000000);

    ll n; cin >> n;
    while (n != 0) {
        eulerPhi(n);
        cin >> n;
    }
}