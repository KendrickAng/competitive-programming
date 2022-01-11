#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

int solve(std::string s, std::string t) {
    if (s.size() != t.size()) {
        return -1;
    }
    // count differences in 1s
    int s1 = 0;
    int t1 = 0;
    for (char c: s) if (c == '1') s1++;
    for (char c: t) if (c == '1') t1++;
    if (s1 > t1) {
        return -1;
    }

    // place 1s into ?s with corresponding 1s
    int moves = 0;
    int onesdiff = t1-s1;
    for (int i = 0; i < s.size(); i++) {
        if (onesdiff > 0 && s[i] == '?' && t[i] == '1') {
            s[i] = '1';
            onesdiff--;
            moves++;
        }
    }
    // place 1s into 0s with corresponding 1s
    for (int i = 0; i < s.size(); i++) {
        if (onesdiff > 0 && s[i] == '0' && t[i] == '1') {
            s[i] = '1';
            onesdiff--;
            moves++;
        }
    }
    assert(onesdiff <= 0);

    // place 0s into remaining ?s, if any
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            s[i] = '0';
            moves++;
        }
    }
    // do swaps
    int diffs = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            diffs++;
        }
    }
    return moves + diffs/2;
}

int main() {
    int N;
    std::string s, t;
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> s >> t;
        std::cout << "Case " << i << ": " << solve(s, t) << std::endl;
    }
}