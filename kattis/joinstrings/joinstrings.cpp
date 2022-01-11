#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> seq{};

void populateSequence(auto &m, vector<int> &vec, int idx) {
    seq.push_back(idx);
    for (int i: vec) {
        populateSequence(m, m[i], i);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<string> strings(n);
    unordered_map<int, vector<int>> mapp(n);
    for (int i = 0; i < n; i++) {
        mapp[i] = vector<int>{};
    }

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int lastIdx;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        mapp[a].push_back(b);
        lastIdx = a;
    }

    populateSequence(mapp, mapp[lastIdx], lastIdx);

    for (int i: seq) {
        cout << strings[i];
    }
    cout << endl;
}
