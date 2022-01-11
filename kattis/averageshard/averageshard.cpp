#include <bits/stdc++.h>

using namespace std;

void solve() {
    int ncs, ne; cin >> ncs >> ne;
    long csSum = 0;
    long csCount = 0;
    long eSum = 0;
    long eCount = 0;

    int tmp;
    vector<int> csScores;
    for (int i = 0; i < ncs; i++) {
        cin >> tmp;
        csSum += tmp;
        csCount ++;
        csScores.push_back(tmp);
    }

    for (int i = 0; i < ne; i++) {
        cin >> tmp;
        eSum += tmp;
        eCount ++;
    }

    double trueCsAvg = (double) csSum / csCount;
    double trueEAvg = (double) eSum / eCount;

    int ans = 0;
    for (int score: csScores) {
        double csAvg = (double) (csSum - score) / (csCount - 1);
        double eAvg = (double) (eSum + score) / (eCount + 1);
        if (csAvg > trueCsAvg and eAvg > trueEAvg) ans++;
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}