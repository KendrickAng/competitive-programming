#include <iostream>
#include <string>
#include <algorithm>

// UNSOLVED PROBLEMMMMMMM
/*
011???
100111

ans: 5
*/
int main() {
    int C;
    std::string S, T;
    std::cin >> C;
    for (int idx = 0; idx < C; idx++) {
        int ans;
        std::cin >> S >> T;
        if (S.length() != T.length()) {
            ans = -1;
        } else {
            // count 0s and 1s in S 
            int s0 = 0;
            int s1 = 0;
            int sqn = 0;
            int t0 = 0;
            int t1 = 0;
            int no_promote = 0;
            int diffs = 0;
            for (int i = 0; i < S.length(); i++) {
                if (S[i] == '0') {
                    s0++;
                }
                if (S[i] == '1') {
                    s1++;
                }
                if (S[i] == '?') {
                    if (T[i] == '1') {
                        no_promote++;
                    }
                    sqn++;
                }
                if (T[i] == '0') {
                    t0++;
                }
                if (T[i] == '1') {
                    t1++;
                }
                if (S[i] != '?' && S[i] != T[i]) {
                    diffs++;
                }
            }
            // verify solvability
            if (s1 > t1) {
                ans = -1;
            } else {
                // solve
                int promotions = t1-no_promote-s1;
                ans = sqn + promotions + ((diffs-promotions)/2);
            }
        }
        std::cout << "Case " << idx+1 << ": " << ans << std::endl;
    }
}