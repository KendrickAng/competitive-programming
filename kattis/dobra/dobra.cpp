#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long ans = 0;
vector<int> ways;

bool isVow(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool isCon(char c) {
    return !isVow(c);
}

long long isPleasant(string &s) {
    bool hasThreeSeqVow = false;
    bool hasThreeSeqCon = false;
    bool hasL = false;
    if (s.size() == 1) hasL = (s[0] == 'L');
    if (s.size() == 2) hasL = (s[0] == 'L' || s[1] == 'L');
    int limit = s.length() - 2;
    for (int i = 0; i < limit; i++) {
        char a = s[i];
        char b = s[i+1];
        char c = s[i+2];
        if (a == 'L' || b == 'L' || c == 'L') {
            hasL = true;
        }
        if (isCon(a) && isCon(b) && isCon(c)) {
            hasThreeSeqCon = true;
        }
        if (isVow(a) && isVow(b) && isVow(c)) {
            hasThreeSeqVow = true;
        }
    }
    if (!hasThreeSeqCon && !hasThreeSeqVow && hasL) {
        long long count = 1;
        for (auto t: ways) count *= t;
        return count;
    }
    return -1;
}

void solve(string &s, int currIdx) {
    if (currIdx == (int) s.length()) {
        long long a = isPleasant(s);
        if (a != -1) ans += a;
        return;
    }
    char c = s[currIdx];
    if (c != '_') {
        solve(s, currIdx+1);
    } else {
        s[currIdx] = 'A'; // vowel
        ways[currIdx] = 5;
        solve(s, currIdx+1);
        ways[currIdx] = 1;
        s[currIdx] = '_';

        s[currIdx] = 'L';
        solve(s, currIdx+1);
        s[currIdx] = '_';

        s[currIdx] = 'D'; // consonant
        ways[currIdx] = 20;
        solve(s, currIdx+1);
        ways[currIdx] = 1;
        s[currIdx] = '_';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s;
    ways.resize(s.length(), 1);
    solve(s, 0);
    cout << ans << endl;
}