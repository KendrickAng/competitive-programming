#include <bits/stdc++.h>

using namespace std;

long long _sieve_size;
bitset<100000> bs;
vector<long long> p;

void sieve(long long n) {
    _sieve_size = n + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i < _sieve_size; i++) {
        if (bs[i]) {
            for (long long j = i*i; j < _sieve_size; j += i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

bool isPrime(long long n) {
    if (n < _sieve_size) return bs[n];
    for (long long i = 0; i < p.size() && p[i]*p[i] <= n; i++) {
        if (n % p[i] == 0) {
            return false;
        }
    }
    return true;
}

long double euclidean(long double x1, long double y1, long double x2, long double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void solve() {
    int n; cin >> n;
    long double maxdist; cin >> maxdist;
    long double sofar = 0;
    int flowers = 0;
    int checkpoint = 0;
    int currX = 0;
    int currY = 0;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        sofar += euclidean(currX, currY, x, y);

        // update position
        currX = x;
        currY = y;

        // update flowers watered
        if (sofar <= maxdist) {
            flowers ++;
            if (isPrime(flowers)) checkpoint = flowers;
        }
    }

    cout << checkpoint << endl;
}

int main() {
    sieve(20000);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}