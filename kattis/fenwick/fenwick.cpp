#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))
using namespace std;

class FenwickTree {
    private:
        vector<long long> ft;

        void print() {
            for (auto i: ft) cout << i << " ";
            cout << endl;
        }
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
            //print();
        }
};

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    // auto start = chrono::high_resolution_clock::now();
    //fast();

    int n, q;
    scanf("%d %d ", &n, &q);

    FenwickTree tree(n);
    
    char cmd;
    int idx, delta;
    for (int i = 0; i < q; i++) {
        scanf("%c ", &cmd);
        if (cmd == '+') { // +
            scanf("%d %d ", &idx, &delta);
            tree.update(idx+1, delta);
        } else { // ?
            scanf("%d ", &idx);
            long long ans = tree.rsq(idx);
            printf("%lld\n", ans);
        }
    }

    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cout << "time taken " << duration.count() << endl;
}