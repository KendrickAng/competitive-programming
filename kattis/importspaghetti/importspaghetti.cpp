#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> am;
vector<vector<int>> parent; // for path reconstruction
vector<string> mapping;
unordered_map<string, int> rmapping;
int inf = 1e9;

void printPath(int i, int j, vector<int> &path) {
    if (i != j) printPath(i, parent[i][j], path);
    path.push_back(j);
}

void printam() {
    for (auto vec: am) {
        for (int tmp: vec) {
            cout << tmp << " ";
        }
        cout << endl;
    }
}

int main() {
    int n; cin >> n;
    am.assign(n, vector<int>(n, inf));
    parent.assign(n, vector<int>(n));

    // init parent array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            parent[i][j] = i;
        }
    }
    
    // read in graph
    string filename;
    for (int i = 0; i < n; i++) {
        cin >> filename;
        mapping.push_back(filename);
        rmapping[filename] = i;
    }

    string name;
    int imports;
    for (int i = 0; i < n; i++) {
        cin >> name >> imports;
        // cout << name << " : " << imports << endl;

        // read import statements
        string line;
        for (int j = 0; j < imports; j++) {
            cin >> line;
            getline(cin, line);
            line = line.substr(line.find_first_not_of(" ")); // remove leading whitespace

            size_t pos = 0;
            string delimiter = ", ";
            string token;
            while ((pos = line.find(delimiter)) != string::npos) {
                token = line.substr(0, pos);
                
                // add edge to am
                // cout << "token : " << token << endl;
                // cout << "edge " << rmapping[name] << " : " << rmapping[token] << endl;
                am[rmapping[name]][rmapping[token]] = 1;

                line.erase(0, pos + delimiter.size());
            }
            am[rmapping[name]][rmapping[line]] = 1;
            // cout << "edge " << rmapping[name] << " : " << rmapping[line] << endl;
        }
    }

    // printam();

    // apsp
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (am[i][k] + am[k][j] < am[i][j]) {
                    am[i][j] = am[i][k] + am[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    // check for SHORTEST cycle
    int shortestLen = 1e9;
    vector<int> shortestPath;
    for (int i = 0; i < n; i++) {
        if (am[i][i] != inf) {
            vector<int> path;
            printPath(i, parent[i][i], path);
            if (path.size() < shortestLen) {
                shortestPath = path;
                shortestLen = path.size();
            }
        }
    }

    if (shortestPath.size() > 0) {
        for (int id: shortestPath) {
            cout << mapping[id] << " ";
        }
        cout << endl;
    } else {
        cout << "SHIP IT" << endl;
    }
}