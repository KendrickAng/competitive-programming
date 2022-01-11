#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>

using namespace std;

vector<bool> isPrime(10000, true);
vector<int> primes;
vector<vector<int>> graph(10000, vector<int>{});

void preprocess() {
    // sieve of erasthothenes
    for (int i = 2; i < sqrt(9999); i++) {
        int j = 2*i;
        while (j <= 9999) {
            isPrime[j] = false;
            j += i;
        }
    }
    for (int i = 1000; i < 10000; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    // bfs
    for (size_t i = 0; i < primes.size(); i++) {
        for (size_t j = i+1; j < primes.size(); j++) {
            int pi = primes[i];
            int ji = primes[j];
            if (pi == ji) continue;
            string is = to_string(pi);
            string js = to_string(ji);
            int diffs = 0;
            for (size_t k = 0; k < is.size(); k++) {
                if (is[k] != js[k]) diffs++;
            }
            if (diffs == 1) {
                graph[pi].push_back(ji);
                graph[ji].push_back(pi);
            }
        }
    }
}

void solve() {
    int l, r; cin >> l >> r;
    if (l == r) {
        cout << 0 << endl;
        return;
    }
    queue<int> q;
    q.push(l);
    int depth = 0;
    set<int> seen;
    while (!q.empty()) {
        int level_size = q.size();

        // keep track of depth - process all nodes before moving onto nect depth
        while (level_size--) {
            int p = q.front(); q.pop();
            for (int neigh: graph[p]) {
                if (neigh == r) goto end;
                if (seen.find(neigh) == seen.end()) {
                    seen.insert(neigh);
                    q.push(neigh);
                }
            }
        }

        depth++;
    }
    end:
    cout << depth+1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    preprocess();
    while (t--) {
        solve();
    }
}