#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    bool ans = false;
    for (int i = 0; i < 5; i++) {
        cin >> s;
        if (s.find("FBI") != string::npos) {
            cout << i + 1 << " ";
            ans = true;
        }
    }
    if (!ans) cout << "HE GOT AWAY!" << endl;
}