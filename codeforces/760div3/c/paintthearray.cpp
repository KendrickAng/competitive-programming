#include <bits/stdc++.h>

using namespace std;

long _sieve_size;
bitset<1000000> bs;
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

set<int> primeFactors(long long num) {
    set<int> ret;
    for (int i = 0; (i < p.size()) && (p[i]*p[i] <= num); i++) {
        while (num % p[i] == 0) {
            num /= p[i];
            ret.insert(p[i]);
        }
    }
    if (num != 1) ret.insert(num);
    return ret; 
}

void solve() {
    int n; cin >> n;
    vector<long long> nums(n);
    long long maxNum = -1;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        maxNum = max(maxNum, nums[i]);
    }

    // check if answer exists
    for (int i = 1; i < n; i++) {
        set<int> primeF1 = primeFactors(nums[i-1]);
        set<int> primeF2 = primeFactors(nums[i]);
        set<int> combine;
        for (int ii: primeF1) {
            if (primeF2.count(ii)) {
                combine.insert(ii);
            }
        }
        if (combine.size() <= 1) {
            cout << "0" << endl;
            return;
        }
    }

    // answer exists - try all nums
    for (int i = 2; i <= maxNum; i++) {
        vector<bool> canDiv;
        for (long long num: nums) {
            if (num % i == 0) {
                if (!canDiv.empty() && canDiv.back() == true) break;
                canDiv.push_back(true);
            } else {
                if (!canDiv.empty() && canDiv.back() == false) break;
                canDiv.push_back(false);
            }
        }
        cout << i << endl;
        return;
    }
}

int main() {
    sieve(1000000);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}