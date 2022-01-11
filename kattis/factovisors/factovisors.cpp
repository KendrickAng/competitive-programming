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

unordered_map<ll, ll> primeFactors(ll num) {
    unordered_map<ll, ll> ret;
    for (int i = 0; i < p.size() && p[i] * p[i] <= num; i++) {
        while (num % p[i] == 0) {
            num /= p[i];
            ret[p[i]] += 1;
        }
    }
    if (num != 1) ret[num] += 1;
    return ret;
}

ll Legendre(ll n, ll factor) {
    int power = 1;
    int temp = floor(n / pow(factor, power++));
    ll ret = temp;
    while (temp > 0) {
        // cout << "hi "  << factor << endl;
        temp = floor(n / pow(factor, power++));
        ret += temp;
    }
    return ret;
}

void solve(ll n, ll m) {
    // cout << "solving " << n << " " << m << endl;
    auto mFactors = primeFactors(m);

    bool isDivisor = true;
    for (const auto &[factor, power]: mFactors) {
        auto nPower = Legendre(n, factor);
        if (nPower == 0 || power > nPower) {
            // if factor doesnt exist in n, cannot divide
            // if factor exists but is greater than that in n, cannot divide
            isDivisor = false;
        }
    }

    if (!isDivisor) {
        cout << m << " does not divide " << n << "!" << endl;
    } else {
        cout << m << " divides " << n << "!" << endl;
    }
}

int main() {
    sieve(1000000);

    ll n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
}