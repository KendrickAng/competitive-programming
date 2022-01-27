#include <bits/stdc++.h>

using namespace std;

unordered_map<string,pair<int,int>> sticks = {
    // remove, add
    {"06", {1,1}},
    {"60", {1,1}},
    {"08", {0,1}},
    {"80", {1,0}},
    {"09", {1,1}},
    {"90", {1,1}},
    {"17", {0,1}},
    {"71", {1,0}},
    {"23", {1,1}},
    {"32", {1,1}},
    {"35", {1,1}},
    {"53", {1,1}},
    {"39", {0,1}},
    {"93", {1,0}},
    {"56", {0,1}},
    {"65", {1,0}},
    {"59", {0,1}},
    {"95", {1,0}},
    {"68", {0,1}},
    {"86", {1,0}},
    {"69", {1,1}},
    {"96", {1,1}},
    {"89", {1,0}},
    {"98", {0,1}},
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string x, y; cin >> x >> y;

    // first check that chars different <= 2
    int diff = 0;
    pair<int,int> sum = {0,0};
    for (int i = 0; i < x.length(); i++) {
        if (x[i] != y[i]) {
            string s = string(1, x[i]) + y[i];
            if (sticks.find(s) == sticks.end()) {
                cout << "no" << endl;
                return 0;
            } else {
                sum.first += sticks[s].first;
                sum.second += sticks[s].second;
            }

            diff++;

            if (diff > 2) {
                cout << "no" << endl;
                return 0;
            }
        }
    }


    if (sum.first == 1 && sum.second == 1) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}