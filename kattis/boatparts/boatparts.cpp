#include <bits/stdc++.h>

using namespace std;

int main() {
    int p, n; scanf("%d%d", &p, &n);
    unordered_set<string> stuff;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        stuff.insert(s);
        if (stuff.size() == p) {
            printf("%d", i+1);
            return 0;
        }
    }
    printf("paradox avoided");
}