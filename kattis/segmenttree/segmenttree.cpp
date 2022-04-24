#include <bits/stdc++.h>
#define ONLINE_JUDGE
using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

using ll = long long;
using ii = pair<int, int>;

class QueryInterface {
   public:
    virtual void increment(int i, int j, int val) = 0;
    virtual int query(int i, int j) = 0;
};

class RangeSlow : public QueryInterface {
   public:
    vector<int> arr;
    RangeSlow(int n) { arr.assign(n+10, 0); }
    void increment(int l, int r, int val) override {
        for (int i = l; i <= r; i++) {
            arr[i] += val;
        }
    }
    int query(int l, int r) override {
        int ans = arr[l];
        for (int i = l+1; i <= r; i++) {
            ans = min(ans, arr[i]);
        }
        return ans;
    }
};

class SegmentTree: public QueryInterface {
    public:
    int n;
    vector<int> lo;
    vector<int> hi;
    vector<int> mins;
    vector<int> delta;
    SegmentTree(int n) {
        this->n = n+1;
        lo.assign(4*n+1, 0);
        hi.assign(4*n+1, 0);
        mins.assign(4*n+1, 0);
        delta.assign(4*n+1, 0);
        init(1, 0, n-1);
    }
    void init(int idx, int l, int r) {
        lo[idx] = l;
        hi[idx] = r;
        if (l == r) return; // already at leaf
        int mid = (l+r) / 2;
        init(2*idx, l, mid);
        init(2*idx+1, mid+1, r);
    }
    void increment(int l, int r, int val) override {
        increment(1, l, r, val);
    }
    void increment(int idx, int l, int r, int val) {
        // outside of range we want to update
        if (r < lo[idx] || hi[idx] < l) return;
        // completely covers range we want to update
        if (l <= lo[idx] and hi[idx] <= r) {
            delta[idx] += val;
            return;
        }
        // partial cover case
        prop(idx);
        increment(2*idx, l, r, val);
        increment(2*idx+1, l, r, val);
        update(idx);
    }
    int query(int l, int r) override {
        return query(1, l, r);
    }
    int query(int idx, int l, int r) {
        if (r < lo[idx] or hi[idx] < l) return INT_MAX;
        if (l <= lo[idx] and hi[idx] <= r) return mins[idx] + delta[idx];
        prop(idx);
        int minLeft = query(2*idx, l, r);
        int minRight = query(2*idx+1, l, r);
        update(idx);
        // change this to modify segment tree function
        return min(minLeft, minRight);
    }
    void prop(int i) {
        delta[2*i] += delta[i];
        delta[2*i+1] += delta[i];
        delta[i] = 0;
    }
    void update(int i) { // change this to modify segment tree function
        mins[i] = min(mins[2*i]+delta[2*i], mins[2*i+1]+delta[2*i+1]);
    }
};

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
            // cout << "set " + to_string(idx) + " to " + to_string(a[tl]) << endl;
            tree[idx] = a[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        build(a, lChild(idx), tl, mid);
        build(a, rChild(idx), mid+1, tr);
        tree[idx] = tree[lChild(idx)] + tree[rChild(idx)];
    }
    int query(int l, int r) {
        debug("st query", l, r);
        return query(ROOT, 0, n-1, l, r);
    }
    int query(int idx, int tl, int tr, int l, int r) {
        assert(l <= r);
        if (r < tl or l > tr) return 0;
        if (l <= tl and tr <= r) return tree[idx];
        int tm = (tl+tr) / 2;
        int leftChild = query(lChild(idx), tl, tm, l, r);
        int rightChild = query(rChild(idx), tm+1, tr, l, r);
        return leftChild + rightChild;
    }
    void update(int pos, int newVal) {
        // cout << "updating " + to_string(pos) + " to " + to_string(newVal) << endl;
        update(ROOT, 0, n-1, pos, newVal);
    }
    void update(int idx, int tl, int tr, int pos, int newVal) {
        if (tl == tr) {
            // cout << "update " + to_string(idx) + " to " + to_string(newVal) << endl;
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

class SumRangeSlow {
private:
    vector<int> arr;
public:
    SumRangeSlow(int n) {
        arr.assign(n, 0);
    }
    void update(int i, int val) {
        arr[i] = val;
    }
    int query(int i, int j) {
        int ret = 0;
        for (int k = i; k <= j; k++) ret += arr[k];
        return ret;
    }
};

void testSumSegmentTree() {
    SumSegmentTree st(1000);
    SumRangeSlow srs(1000);
    cout << 1 << endl;
    for (int i = 0; i < 10000; i++) {
        cout << i << endl;
        int pos = rand()%1000;
        int val = rand()%10000;
        debug("update", pos, val);
        st.update(pos, val);
        srs.update(pos, val);
        int left = rand()%1000;
        int right = left + rand()%(1000-left);
        debug("query", left, right);
        int stQuery = st.query(left,right);
        int srsQuery = srs.query(left,right);
        if (stQuery != srsQuery) {
            cout << "st: " << stQuery << " " << left << " " << right << endl;
            cout << "srs: " << srsQuery << " " << left << " " << right << endl;
            break;
        }
    }
}

void testMinSegmentTree() {
    QueryInterface *brute = new RangeSlow(10);
    QueryInterface *seg = new SegmentTree(10);
    cout << brute->query(0, 5) << endl;
    cout << seg->query(0, 5) << endl;
    brute->increment(1, 6, 2);
    seg->increment(1, 6, 2);
    cout << brute->query(1, 6) << endl;
    cout << seg->query(1, 6) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    testSumSegmentTree();
}
