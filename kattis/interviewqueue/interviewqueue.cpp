#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> orig(n); // track the original candidates
    vector<int> inQueue(n, true); // track whether candidates already left queue
    list<int> cnd; // represents the actual state of the queue
    vector<list<int>::iterator> cndIts; // maps candidate indexes to position in cnd
    set<int> backlog; // after a candidate leaves, his left/right must be checked
    for (int i = 0; i < n; i++) {
        int tmp; cin >> orig[i];
        cnd.push_back(i);
        cndIts.push_back(prev(cnd.end()));
        backlog.insert(i);
    }

    // n == 1 -> base case
    if (n == 1) {
        cout << 0 << endl;
        cout << orig[0] << endl;
        exit(0);
    }

    vector<vector<int>> iterations;
    while (!backlog.empty()) {
        vector<int> iteration;
        set<int> toSeeLater;

        // check backlog
        for (int idx: backlog) {
            assert(inQueue[idx]);
            auto it = cndIts[idx];
            
            // check left and right candidates
            if (next(it) != cnd.end() && orig[*it] < orig[*next(it)])  {
                inQueue[*it] = false;
            }
            if (it != cnd.begin() && orig[*it] < orig[*prev(it)]) {
                inQueue[*it] = false;
            }

            // if candidate will be removed, add neighbours to be checked in later rounds
            if (!inQueue[idx]) {
                iteration.push_back(orig[idx]);
                if (next(it) != cnd.end()) toSeeLater.insert(*next(it));
                if (it != cnd.begin()) toSeeLater.insert(*prev(it));
            }
        }

        // actually remove iterators
        for (int idx: backlog) {
            if (!inQueue[idx]) cnd.erase(cndIts[idx]);
        }
        backlog.clear();
        for (int idx: toSeeLater) {
            if (inQueue[idx]) backlog.insert(idx);
        }

        if (!iteration.empty()) iterations.push_back(iteration);
    }

    // print answer
    cout << iterations.size() << endl;
    for (auto v: iterations) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
    for (auto i: cnd) {
        cout << orig[i] << " ";
    }
    cout << endl;
}