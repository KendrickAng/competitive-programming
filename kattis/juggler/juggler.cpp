#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))
using namespace std;
using ll = long long;


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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> iToKi(n);
    vector<int> kiToI(n+1);
    list<int> idxs;
    vector<list<int>::iterator> idxToIts;
    FenwickTree ft(n+10);

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        iToKi[i] = tmp;
        kiToI[tmp] = i;
        idxs.push_back(i);
        idxToIts.push_back(prev(idxs.end()));
        ft.update(i+1, 1);
    }

    ll ans = 0;
    int rem = n;
    int prevI = 0;
    int prevKi = iToKi[0];
    for (int ki = 1; ki <= n; ki++) {
        // calc min offset from previous pos
        int currI = kiToI[ki];
        int turnLeft;
        if (prevI < currI)
            turnLeft = ft.rsq(prevI+1, currI+1) - 1; // clockwise
        else
            turnLeft = ft.rsq(currI+1, prevI+1) - 1;
        int turnRight = rem - turnLeft; // anticlock

        // add min offset
        ans += min(turnLeft, turnRight);
        ans++; // drop the ball

        // remove from LL
        auto it = idxToIts[currI];
        if (next(it) == idxs.end()) it = idxs.begin();
        else it = next(it);
        idxs.erase(idxToIts[currI]);

        // update
        ft.update(currI+1, -1);
        prevI = *it; // use the idx after moving from LL, not currI
        prevKi = iToKi[prevI];
        rem--;
    }

    cout << ans << endl;
}