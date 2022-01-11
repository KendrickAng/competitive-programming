#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> choices{};
    for (int i = 0; i < n; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        vector<int> tmp = {a,b,c,d,e};
        sort(tmp.begin(), tmp.end());
        string s = "";
        for (int a: tmp) s.append(to_string(a));
        choices[s] ++;
    }
    int maxx = -1;
    for (auto [k, v]: choices) {
        maxx = max(maxx, v);
    }
    if (maxx == 1) {
        cout << n << endl;
        return 0;
    }
    int total = 0;
    for (auto [k, v]: choices) {
        if (v == maxx) total += v;
    }
    cout << total << endl;
}
