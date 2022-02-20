#include <bits/stdc++.h>

using namespace std;

#define var(x) {cout << #x << " = " << x << " " << endl;}
#define var2(x,y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define var3(x,y,z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}

const int MAX_N = 100010;

int n, k;

void print(vector<int> arr) {
    for (int i: arr) cout << i << ' '; cout << endl;
}

int LIS(vector<int> &arr) {
    vector<int> lis(n, 0);
    vector<int> lisIdx(n, 0);
    int k = 0;

    for (int i = 0; i < n; i++) {
        // find position of smallest element >= arr[i]
        int pos = upper_bound(lis.begin(), lis.begin()+k, arr[i]) - lis.begin();
        lis[pos] = arr[i];
        lisIdx[pos] = i;
        // if we inserted at end of lis, increase its size
        if (pos == k) k++;
        // print(lis);
    }

    return k;
}

void solve() {
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    // print(arr);

    vector<int> copy(arr);
    sort(copy.begin(), copy.end());

    unordered_map<int, int> mapping;
    for (int i = 0; i < n; i++) {
        mapping[copy[i]] = i/k;
    }

    vector<int> mapped(n);
    for (int i = 0; i < n; i++) {
        mapped[i] = mapping[arr[i]];
    }
    
    // print(mapped);

    cout << n - LIS(mapped) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
