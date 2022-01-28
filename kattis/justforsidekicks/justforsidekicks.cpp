#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl '\n'
#define LSOne(S) ((S) & -(S))

class FenwickTree {
    private:
        vector<long long> ft;
    public:
        FenwickTree(int numItems) {
            ft.assign(numItems+1, 0);
        }

        long long rsq(int idx) {
            long long sum = 0;
            for (; idx; idx -= LSOne(idx)) {
                sum += ft[idx];
            }
            return sum;
        }

        // [i, j] both inclusive
        long long rsq(int i, int j) {
            return rsq(j) - rsq(i-1);
        }

        // adds/subtracts a value, NOT replace
        void update(int idx, int val) {
            for (; idx < (int) ft.size(); idx += LSOne(idx)) {
                ft[idx] += val;
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q; cin >> n >> q;
    
    // read in values
    vector<int> values(7);
    for (int i = 1; i <= 6; i++) {
        cin >> values[i];
    }

    // read in initial gem types
    vector<FenwickTree> trees;
    trees.push_back(FenwickTree(0));
    for (int i = 0; i < 6; i++) {
        trees.push_back(FenwickTree(200010));
    }
    string gems; cin >> gems;
    for (int i = 1; i <= n; i++) {
        trees[gems[i-1] - '0'].update(i, 1);
    }

    // read queries
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        switch (type) {
            case 1: {
                int idx, toType; cin >> idx >> toType;
                trees[gems[idx-1] - '0'].update(idx, -1);
                gems[idx-1] = toType + '0';
                trees[gems[idx-1] - '0'].update(idx, 1);
                break;
            }
            case 2: {
                int gemIdx, toVal; cin >> gemIdx >> toVal;
                values[gemIdx] = toVal;
                break;
            }
            case 3: {
                int from, to; cin >> from >> to;
                ll total = 0;
                for (int i = 1; i <= 6; i++) {
                    total += trees[i].rsq(from, to) * values[i];
                }
                cout << total << endl;
            }
        }
    }
}