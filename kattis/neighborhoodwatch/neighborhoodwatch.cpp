#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    long long total = n * (n+1) / 2;

    vector<int> safeHouses;
    safeHouses.push_back(0);
    for (int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        safeHouses.push_back(tmp);
    }
    safeHouses.push_back(n+1);

    for (int i = 1; i < safeHouses.size(); i++) {
        long long unsafeHouses = safeHouses[i] - safeHouses[i-1] - 1;
        total -= unsafeHouses * (unsafeHouses+1) / 2;
    }

    cout << total << endl;
}