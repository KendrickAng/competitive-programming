#include <unordered_map>
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> pts;
    int n, p, m; cin >> n >> p >> m;

    // fill players
    for (int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        pts[tmp] = 0;
    }

    // fill points
    vector<string> winners;
    set<string> won;
    for (int i = 0; i < m; i++) {
        string player;
        int point;
        cin >> player >> point;
        pts[player] += point;
        if (pts[player] >= p && won.count(player) == 0) {
            won.insert(player);
            winners.push_back(player);
        }
    }

    if (winners.size() == 0) {
        cout << "No winner!" << endl;
    } else {
        for (auto s: winners) {
            cout << s << " wins!" << endl;
        }
    }
}