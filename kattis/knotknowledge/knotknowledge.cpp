#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    unordered_set<int> a, b;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a.insert(tmp);
    }
    for (int i = 0; i < n-1; i++) {
        int tmp; cin >> tmp;
        a.erase(tmp);
    }
    cout << *a.begin() << endl;
}