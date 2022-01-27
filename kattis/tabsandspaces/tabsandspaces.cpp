#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // read all files
    vector<int> lines;
    int f; cin >> f;
    for (int i = 0; i < f; i++) {
        // read lines in a file
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int tmp; cin >> tmp;
            lines.push_back(tmp);
        }
    }

    // try all spaces
    int tabSize = -1;
    int maxSaved = -1;
    for (int spaces = 1; spaces <= 79; spaces++) {
        int currSaved = 0;
        for (int lineLen: lines) {
            currSaved += lineLen - (lineLen / spaces) - (lineLen % spaces);
        }
        if (currSaved > maxSaved) {
            tabSize = spaces;
            maxSaved = currSaved;
        }
    }

    cout << tabSize << endl;
    cout << maxSaved << endl;
}