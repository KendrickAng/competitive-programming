#include <bits/stdc++.h>
using namespace std;

class SumSegmentTree {
private:
    const int ROOT = 1;
    int lChild(int i) {
        return 2*i;
    }
    int rChild(int i) {
        return 2*i+1;
    }
public:
    int n;
    vector<int> tree;

    SumSegmentTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
    }
    SumSegmentTree(const vector<int> &a) {
        this->n = a.size();
        tree.assign(4*n, 0);
        build(a, ROOT, 0, n-1);
    }
    void build(const vector<int> &a, int idx, int tl, int tr) {
        if (tl == tr) {
            tree[idx] = a[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        build(a, lChild(idx), tl, mid);
        build(a, rChild(idx), mid+1, tr);
        tree[idx] = tree[lChild(idx)] + tree[rChild(idx)];
    }
    int query(int l, int r) {
        return query(ROOT, 0, n-1, l, r);
    }
    int query(int idx, int tl, int tr, int l, int r) {
        if (r < tl or l > tr) return 0;
        if (l <= tl and tr <= r) return tree[idx];
        int tm = (tl+tr) / 2;
        int leftChild = query(lChild(idx), tl, tm, l, r);
        int rightChild = query(rChild(idx), tm+1, tr, l, r);
        return leftChild + rightChild;
    }
    void update(int pos, int newVal) {
        update(ROOT, 0, n-1, pos, newVal);
    }
    void update(int idx, int tl, int tr, int pos, int newVal) {
        if (tl == tr) {
            tree[idx] = newVal;
            return;
        }
        int mid = (tl+tr)/2;
        if (pos <= mid) {
            update(lChild(idx), tl, mid, pos, newVal);
        } else {
            update(rChild(idx), mid+1, tr, pos, newVal);
        }
        tree[idx] = tree[lChild(idx)] + tree[rChild(idx)];
    }
    void print() {
        for (int i = 0; i < 3*n; i++) {
            cout << i << "\t";
        }
        cout << endl;
        for (int i = 0; i < 3*n; i++) {
            cout << tree[i] << "\t";
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    SumSegmentTree st(N+10);
    for (int i = 0; i < K; i++) {
        char cmd; cin >> cmd;
        if (cmd == 'C') {
            int l, r; cin >> l >> r; 
            l--; r--;
            cout << st.query(l, r) << endl;
        } else if (cmd == 'F') {
            int flip; cin >> flip;
            flip--;
            if (st.query(flip, flip) == 0) {
                st.update(flip, 1);
            } else {
                st.update(flip, 0);
            }
        }
    }
}