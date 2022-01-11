#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    double inf = 1e9;
    vector<vector<double>> am(n, vector<double>(n, 0.0));

    unordered_map<string,int> conv;
    for (int i = 0; i < n; i++) {
        string currency; cin >> currency;
        conv[currency] = i;
        am[i][i] = 1.0;
    }

    int numRates; cin >> numRates;
    for (int i = 0; i < numRates; i++) {
        string sa, sb; cin >> sa >> sb;
        int ra, rb;
        cin >> ra; cin.ignore(); cin >> rb;
        // cout << ra << " : " << rb << endl;
        int aid = conv[sa];
        int bid = conv[sb];
        am[aid][bid] = (double) rb / (double) ra;
    }

    // apsp
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                am[i][j] = max(am[i][j], am[i][k] * am[k][j]);
            }
        }
    }

    // check for positive cycle
    bool arbitrage = false;
    for (int i = 0; i < n; i++) {
        if (am[i][i] > 1.0) {
            arbitrage = true;
            break;
        }
    }

    if (arbitrage) {
        cout << "Arbitrage" << endl;
    } else {
        cout << "Ok" << endl;
    }
}

int main() {
    int numCurrencies; cin >> numCurrencies;
    while (numCurrencies != 0) {
        solve(numCurrencies);
        cin >> numCurrencies;
    }
}