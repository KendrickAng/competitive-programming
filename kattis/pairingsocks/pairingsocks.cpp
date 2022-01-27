#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    stack<int> a;
    int ans = 0;
    for (int i = 0; i < 2*n; i++) {
        int tmp; cin >> tmp;
        if (!a.empty() and (a.top() == tmp)) {
            a.pop();
            ans += 2;
        } else {
            a.push(tmp);
        }
    }

    if (a.empty()) {
        cout << ans << endl;
    } else {
        cout << "impossible" << endl;
    }
}