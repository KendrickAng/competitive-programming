#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> hist(30, 0);

    string code, guess; cin >> code >> guess;
    int exact = 0;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (code[i] == guess[i]) {
            exact++;
            guess[i] = 'Z' + 1;
        } else {
            hist[(code[i] - 'A')]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (guess[i] == 'Z'+1) continue;
        
        if (hist[(guess[i] - 'A')] > 0) {
            hist[(guess[i] - 'A')]--;
            pos++;
        }
    }

    cout << exact << " " << pos << endl;
}