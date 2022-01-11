#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

unordered_map<int, vector<int>> m{};
int offset;
int num;

void solvee(string s, char curr, int k, int len) {
    if (s.size() == len) {
        int i = stoi(s);
        int newOffset = abs(i - k);
        if (newOffset < offset) {
            offset = newOffset;
            num = i;
        }
        return;
    }
    // use the current
    for (char a: m[curr]) {
        s.push_back(curr);
        solvee(s, a, k, len);
        s.pop_back();
    }
}

void solve(int k, int len) {
    char starts[] = {'1','2','3','4','5','6','7','8','9','0'};
    for (char c: starts) {
        solvee("", c, k, len);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    m['1'] = {'1','2','3','4','5','6','7','8','9','0'};
    m['2'] = {'2','3','5','6','8','9','0'};
    m['3'] = {'3','6','9'};
    m['4'] = {'4','5','6','7','8','9','0'};
    m['5'] = {'5','6','8','9','0'};
    m['6'] = {'6','9'};
    m['7'] = {'7','8','9','0'};
    m['8'] = {'8','9','0'};
    m['9'] = {'9'};
    m['0'] = {'0'};

    int t; cin >> t;
    while (t--) {
        offset = 1000;
        num = -1;

        int k; cin >> k;
        int len = to_string(k).size();

        solve(k, len);
        cout << num << endl;
    }
}