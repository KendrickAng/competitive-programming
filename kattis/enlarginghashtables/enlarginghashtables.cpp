#include <bits/stdc++.h>

using namespace std;

long _sieve_size;
bitset<100000> bs;
vector<long> p;

void sieve(long upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long i = 2; i < _sieve_size; i++) {
        if (bs[i]) {
            for (long j = i*i; j < _sieve_size; j+= i) {
                bs[j] = 0;
            }
            p.push_back(i); // i is a prime
        }
    }
}

// check if n is divisible by prime divisors <= sqrt(n)
bool isPrime(long n) {
    if (n < _sieve_size) return bs[n];
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; i++) {
        if (n % p[i] == 0) return false;
    }
    return true;
}

int main() {
    sieve(100000);
    
    long num;
    while (true) {
        cin >> num;
        if (num == 0) break;

        bool isNumPrime = isPrime(num);
        for (long i = 2*num+1; ; i++) {
            if (isPrime(i)) {
                if (isNumPrime) {
                    cout << i << endl;
                } else {
                    cout << i << " (" << num << " is not prime)" << endl;
                }
                break;
            }
        }
    }
}