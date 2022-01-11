#include <bits/stdc++.h>

using namespace std;
using ll = long long;


bitset<1000010> bs;
ll _sieve_size;
vector<ll> p;

void sieve(ll n) {
    _sieve_size = n + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; i++) {
        if (bs[i]) {
            for (ll j = i*i; j < _sieve_size; j += i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

bool isPrime(ll n) {
    if (n < 0) n = -n;
    if (n < _sieve_size) return bs[n];
    for (int i = 0; i < p.size() && p[i]*p[i] <= n; i++) {
        if (n % p[i] == 0) {
            return false;
        }
    }
    return true;
}

string primeFactors(ll n) {
    string ret = "";
    if (n < 0) {
        ret += "-1 ";
        n = -n;
    }
    // cout << "n is " << n << endl;

    for (ll i = 0; i < p.size() && p[i]*p[i] <= n; i++) {
        int exponent = 0;
        while (n % p[i] == 0) {
            n /= p[i];
            exponent += 1;
        }
        if (exponent > 1) {
            ret += to_string(p[i]);
            ret += "^";
            ret += to_string(exponent) + " ";
        } else if (exponent == 1) {
            ret += to_string(p[i]) + " ";
        }
    }
    if (n != 1) ret += to_string(n);

    return ret;
}

int main() {
    sieve(1000000);
    // for (int i = 0; i < 10; i++) {
    //     cout << p[i] << endl;
    // }

    ll n;
    while (cin >> n) {
        // cout << "now testing " << n << endl;
        if (isPrime(n)) {
            if (n < 0) {
                cout << "-1 " << -n << endl;
            } else {
                cout << n << endl;
            }
        } else {
            cout << primeFactors(n) << endl;
        }
    } 
}