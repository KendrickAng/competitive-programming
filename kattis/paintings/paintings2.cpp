#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
vector<string> prefColors{};
set<pair<string, string>> hatedPairs{};
unordered_map<string, string> colorToKey{};
int nonHideous = 0;
vector<pair<string, string>> paintings{};

void solve2(vector<string> &painting, string key, string prev, int lines) {
    if (lines == n) {
        string s = "";
        for (auto a: painting) {
            s += a;
            s += " ";
        }
        // cout << key << " : " << s << endl;
        paintings.push_back({key, s});
        return;
    }
    // add a non-hideous color
    for (int i = 0; i < prefColors.size(); i++) {
        if (prefColors[i] == "") { // color has been used
            continue;
        }
        string s = prefColors[i];
        string prevCopy = prev;
        bool isHated;
        if (s > prevCopy) {
            isHated = hatedPairs.count({prevCopy, s}) != 0;
        } else {
            isHated = hatedPairs.count({s, prevCopy}) != 0;
        }
        if (!isHated) {
            prefColors[i] = "";
            painting.push_back(s);
            solve2(painting, key+colorToKey[s], s, lines+1);
            prefColors[i] = s;
            painting.pop_back();
        }
    }
}

void solve() {
    vector<string> tmp{};
    solve2(tmp, "", "", 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        prefColors.clear();
        colorToKey.clear();
        hatedPairs.clear();
        paintings.clear();
        cin >> n;

        // preferred colors
        for (int i = 0; i < n; i++) {
            string tmp; cin >> tmp;
            prefColors.push_back(tmp);
            colorToKey[tmp] = (char) ('a'+i);
        }

        // hated pairs of colors
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            string a, b; cin >> a >> b;
            if (a > b) {
                swap(a, b);
            }
            hatedPairs.insert({a,b});
        }

        // construct all colors
        solve();
        sort(paintings.begin(), paintings.end());
        cout << paintings.size() << endl;
        cout << paintings[0].second << endl;
    }
}