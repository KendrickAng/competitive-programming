#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    string s;
    int n; cin >> n >> s;
    vector<long> mid(n);
    vector<long> left(n);
    vector<long> right(n);
    for (int i = 0; i < s.size(); i++) mid[i] = s[i] - '0';
    
    // create left arr
    int dist = 1e9;
    for (int i = 0; i < n; i++) {
        dist++;
        if (mid[i] == 1) dist = 0;
        left[i] = dist;
    }
    
    // create right arr
    dist = 1e9;
    for (int i = n-1; i >= 0; i--) {
        dist++;
        if (mid[i] == 1) dist = 0;
        right[i] = dist;
    }

    // for (int i: mid) cout << i << " "; cout << endl;
    // for (int i: right) cout << i << " "; cout << endl;
    // merge both arrs
    for (int i = 0; i < n; i++) {
        left[i] = min(left[i], right[i]);
    }
    
    long sum = 0;
    for (long i: left) sum += i;
    
    cout << "Case #" << t << ": " << sum << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}