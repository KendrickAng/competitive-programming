#include <bits/stdc++.h>

using namespace std;

enum {
    UNVISITED
};

unordered_map<string,int> mapping;
vector<string> speaks;
vector<unordered_set<string>> understands;

vector<vector<int>> adjList;
vector<int> dfs_num;
vector<int> dfs_low;
vector<bool> visited;
stack<int> stk;

int dfsNumberCounter;
int numSCC;
int maxSCCSize;

void tarjanSCC(int u) {
    dfs_num[u] = dfsNumberCounter++;
    dfs_low[u] = dfs_num[u];
    stk.push(u);
    visited[u] = true;

    for (int v: adjList[u]) {
        if (dfs_num[v] == UNVISITED) {
            tarjanSCC(v);
        }
        if (visited[v]) { // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_low[u] == dfs_num[u]) { // reached start of an SCC
        numSCC++;
        int sccSize = 0;
        // cout << "found scc" << endl;
        while (true) {
            int v = stk.top(); stk.pop();
            // cout << " " << v;
            sccSize++;
            visited[v] = false;
            if (u == v) {
                break;
            }
        }
        // cout << endl;
        maxSCCSize = max(maxSCCSize, sccSize);
    }
}

int main() {
    int n; cin >> n;

    // initialize data structures for Tarjan's SCC
    speaks.resize(n);
    understands.assign(n, unordered_set<string>());
    adjList.assign(n, vector<int>());
    dfs_num.assign(n, UNVISITED);
    dfs_low.assign(n, -1);
    visited.assign(n, false);

    // read in input
    int id = 0;
    string line;
    string name;
    string tmp;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        
        // assign a unique id to a person
        ss >> name;
        mapping[name] = id++;
        // cout << id - 1 << " : " << name << endl;

        // fill in language spoken by person
        int nid = mapping[name];
        ss >> tmp;
        speaks[nid] = tmp;
        understands[nid].insert(tmp); // if a person speaks a language he understands it too
        
        // fill in language understood by person
        while (ss >> tmp) {
            understands[nid].insert(tmp);
        }
    }

    // build graph
    for (int u = 0; u < speaks.size(); u++) {
        for (int v = 0; v < understands.size(); v++) {
            if (u == v) continue;
            string &spoken = speaks[u];
            unordered_set<string> &understood = understands[v];
            // u speaks what v understands means edge u -> v exists
            if (understood.find(spoken) != understood.end()) {
                adjList[u].push_back(v);
            }
        }
    }

    while (!stk.empty()) stk.pop();
    dfsNumberCounter = 0;
    numSCC = 0;
    maxSCCSize = -1;

    for (int u = 0; u < n; u++) {
        if (dfs_num[u] == UNVISITED) {
            tarjanSCC(u);
        }
    }

    cout << n - maxSCCSize << endl;
}