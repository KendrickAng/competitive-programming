#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    list<string> line;
    
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        line.push_back(tmp);
    }

    // fill in mapping
    unordered_map<string, list<string>::iterator> mapping;
    for (auto it = line.begin(); it != line.end(); it++) {
        mapping[*it] = it;
    }

    int c; cin >> c;
    string cmd;
    for (int i = 0; i < c; i++) {
        cin >> cmd;
        if (cmd == "cut") {
            string a, b; cin >> a >> b;
            auto it = mapping[b];
            line.insert(it, a);
            mapping[a] = prev(it);
        } else {
            string leaving; cin >> leaving;
            auto it = mapping[leaving];
            line.erase(it);
            mapping.erase(leaving);
        }
    }

    for (string s: line) {
        cout << s << endl;
    }
}