#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    int upperBound = INT_MAX;
    int lowerBound = 0;
    vector<int> divisors;

    for (int i = 0; i < n; i++) {
        int num;
        string op, tmp; 
        cin >> op >> tmp >> num;
        // cout << op << " " << tmp << " " << num << endl;
        if (op == "greater") {
            lowerBound = max(lowerBound, num);
        } else if (op == "less") {
            upperBound = min(upperBound, num);
        } else { // divisible by
            divisors.push_back(num);
        }
    }

    if (upperBound == INT_MAX) {
        cout << "infinite" << endl;
        return;
    }

    bool hasAns = false;
    for (int i = lowerBound+1; i < upperBound; i++) {
        bool ok = true;
        for (int d: divisors) {
            if (i % d != 0) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << i << " ";
            hasAns = true;
        }
    }

    if (hasAns) {
        cout << endl;
    } else {
        cout << "none" << endl;
    }
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
}