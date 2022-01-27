#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // read input
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> start(n+1, -1);
    vector<int> end(n+1);
    for (int i = 0; i < n; i++) {
        int color = arr[i];
        if (start[color] == -1) {
            start[color] = i;
        }
        end[color] = i;
    }
    
    stack<int> stk;
    stack<string> instr;
    for (int i = 0; i < n; i++) {
        int color = arr[i];

        if (stk.empty()) {
            stk.push(color);
            continue;
        }
        if (start[color] == i && end[color] == i) {
            string ans = to_string(start[color]+1) + " " + to_string(end[color]+1) + " " + to_string(color);
            instr.push(ans);
        } else if (start[color] == i) {
            stk.push(color);
        } else if (end[color] != i && stk.top() == color) {
            continue;
        } else if (end[color] == i && stk.top() != color) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        } else if (end[color] == i && stk.top() == color) {
            stk.pop();
            string ans = to_string(start[color]+1) + " " + to_string(end[color]+1) + " " + to_string(color);
            instr.push(ans);
        }
    }
    while (!stk.empty()) {
        int color = stk.top(); stk.pop();
        string ans = to_string(start[color]+1) + " " + to_string(end[color]+1) + " " + to_string(color);
        instr.push(ans);
    }

    cout << instr.size() << endl;
    while (!instr.empty()) {
        cout << instr.top() << endl;
        instr.pop();
    }
}