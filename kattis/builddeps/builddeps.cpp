#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> adjList;
stack<string> order;
unordered_set<string> visited;

void toposort(string &start) {
    visited.insert(start);
    for (string &neigh: adjList[start]) {
        if (visited.find(neigh) == visited.end()) {
            toposort(neigh);
        }
    }
    order.push(start);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    string line;
    string tmp;
    string filename;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);

        ss >> filename;
        filename.pop_back(); // remove colon
        //cout << filename2 << endl;
        while (ss >> tmp) {
            //cout << tmp << endl;
            if (adjList.find(tmp) == adjList.end()) adjList[tmp] = vector<string>();
            adjList[tmp].push_back(filename);
        }
    }

    string root; cin >> root;
    toposort(root);

    while (!order.empty()) {
        string &tmp = order.top();
        cout << tmp << endl;
        order.pop();
    }
}