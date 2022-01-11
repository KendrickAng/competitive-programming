// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

vector<vector<char>> arr;
vector<vector<bool>> depth;
vector<vector<int>> ptToID;
UnionFind uf(0);

void unionSet(const pair<int,int> &a, const pair<int,int> &b) {
    //cout << "union " << a.first << " " << a.second << " and " << b.first << " " << b.second << endl; 
    int ia = ptToID[a.first][a.second];
    int ib = ptToID[b.first][b.second];
    uf.unionSet(ia, ib);
}

bool isSameSet(const pair<int,int> &a, const pair<int,int> &b) {
    int ia = ptToID[a.first][a.second];
    int ib = ptToID[b.first][b.second];
    // cout << "sameset pair " << a.first << " " << a.second << " and " << b.first << " " << b.second << endl; 
    // cout << "sameset id " << ia << " and " << ib << endl;
    return uf.isSameSet(ia, ib);
}

void flood(int row, int col, char c, const pair<int,int> &key) {
    //cout << row << ' ' << col << endl;
    if (row < 0 || row >= arr.size() || col < 0 || col >= arr[0].size()) return;
    if (arr[row][col] != c) return; // only flood until we need to
    if (depth[row][col]) return;
    unionSet(key, {row, col});
    depth[row][col] = true; // mark traversed
    
    int rOff[] = {-1, 0, 1, 0}; // N E S W
    int cOff[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        flood(row+rOff[i], col+cOff[i], c, key);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // read input
    int r, c; cin >> r >> c;
    int id = 0; // UFDS stars with id 0
    arr = vector<vector<char>>(r, vector<char>(c));
    depth = vector<vector<bool>>(r, vector<bool>(c, false));
    ptToID = vector<vector<int>>(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ptToID[i][j] = id++;
            cin >> arr[i][j];
        }
    }
    // form disjoint set
    uf = UnionFind(r*c);
    // intelligent flood fill
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!depth[i][j]) {
                flood(i, j, arr[i][j], {i,j});
            }
        }
    }
    // answer queries
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        pair<int,int> a = {r1, c1};
        pair<int,int> b = {r2, c2};
        bool sameSet = (a == b) || isSameSet(a, b);
        if (sameSet && arr[r1][c1] == '0') {
            cout << "binary" << endl;
        }
        else if (sameSet && arr[r1][c1] == '1') {
            cout << "decimal" << endl;
        }
        else {
            cout << "neither" << endl;
        }
    }
}