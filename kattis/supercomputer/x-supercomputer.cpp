#include <bits/stdc++.h>

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

class SegmentTree {
   private:
   const int ROOT = 1;
   int leftChild(int i) { return 2*i; }
   int rightChild(int i) { return 2*i+1;}
   public:
    vector<int> lowerBound;
    vector<int> upperBound;
    vector<int> mins;
    vector<int> delta;
    SegmentTree(int n) {
        lowerBound.assign(4 * n + 1, 0);
        upperBound.assign(4 * n + 1, 0);
        mins.assign(4 * n + 1, 0);
        delta.assign(4 * n + 1, 0);
        init(ROOT, 1, n); // 1-indexed
    }
    void init(int idx, int l, int r) {
        lowerBound[idx] = l;
        upperBound[idx] = r;
        if (l == r) return;  // already at leaf
        int mid = (l + r) / 2;
        init(leftChild(idx), l, mid);
        init(rightChild(idx), mid+1, r);
    }
    void increment(int l, int r, int val) { 
        increment(ROOT, l, r, val); 
    }
    void increment(int idx, int l, int r, int val) {
        // outside of range we want to update
        if ((r < lowerBound[idx]) || (upperBound[idx] < l)) {
            return;
        }
        // completely covers range we want to update
        if ((l <= lowerBound[idx]) and (upperBound[idx] <= r)) {
            debug("increment", lowerBound[idx], upperBound[idx], val);
            delta[idx] += (r-l+1)*val;
            return;
        }
        // partial cover case
        prop(idx); // progate current delta to children
        increment(leftChild(idx), l, r, val);
        increment(rightChild(idx), l, r, val);
        update(idx); // update actual values
    }
    int sum(int l, int r) {
        debug("sum", l, r);
        return sum(ROOT, l, r);
    }
    int sum(int idx, int l, int r) {
        if ((r < lowerBound[idx]) or (upperBound[idx] < l)) {
            debug(lowerBound[idx], upperBound[idx], 0);
            return 0;
        }
        if ((l <= lowerBound[idx]) and (upperBound[idx] <= r)) {
            debug(lowerBound[idx], upperBound[idx], mins[idx] + delta[idx]);
            return mins[idx] + delta[idx];
        }
        prop(idx);
        int minLeft = sum(leftChild(idx), l, r);
        int minRight = sum(rightChild(idx), l, r);
        update(idx);
        // change this to modify segment tree function
        return minLeft + minRight;
    }
    void prop(int i) {
        delta[leftChild(i)] += delta[i];
        delta[rightChild(i)] += delta[i];
        delta[i] = 0;
    }
    void update(int i) {  // change this to modify segment tree function
        mins[i] = mins[leftChild(i)] + delta[leftChild(i)] + mins[rightChild(i)] + delta[rightChild(i)];
    }
};

void test() {
    SegmentTree tree(10);
    cout << tree.sum(1, 10) << endl;
    tree.increment(1, 10, 1);
    cout << tree.sum(1, 10) << endl; // 10
    tree.increment(1, 4, 2);
    cout << tree.sum(1, 4) << endl;  // 16
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test();
    // int N, K; cin >> N >> K;
    // SegmentTree tree(N+10);
    // for (int i = 0; i < K; i++) {
    //     char cmd; cin >> cmd;
    //     if (cmd == 'C') {
    //         int l, r; cin >> l >> r;
    //         cout << tree.query(l, r) << endl;
    //     } else if (cmd == 'F') {
    //         int idx; cin >> idx;
    //         if (tree.function(idx, idx) == 0) {
    //             tree.increment(idx, idx, 1);
    //         } else {
    //             tree.increment(idx, idx, -1);
    //         }
    //     }
    // }
}