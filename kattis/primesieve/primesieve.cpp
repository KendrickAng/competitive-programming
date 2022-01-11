#include <bits/stdc++.h>

using namespace std;

bitset<100000010> bits; // fixed size
long _sieve_size;
vector<int> primes;
long numPrimes;

void sieve(int n) {
    _sieve_size = n + 1;
    bits.set();
    bits[0] = bits[1] = 0; // 0 and 1 considered not prime
    numPrimes -= 2;
    for (long long i = 2; i < _sieve_size; i++) {
        if (bits[i]) {
            for (long long j = i*i; j < _sieve_size; j += i) { // optimisation
                if (bits[j]) {
                    bits[j] = 0;
                    numPrimes --;
                }
            }
            primes.push_back((int) i);
        }
    }
}

bool isPrime(long long n) {
    if (n <= _sieve_size) return bits[n];
    for (int i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, q; cin >> n >> q;

    numPrimes = n+1;
    sieve(n); // should not exceed bitset size
    cout << numPrimes << endl;

    for (int i = 0; i < q; i++) {
        int tmp; cin >> tmp;
        if (isPrime(tmp)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
}