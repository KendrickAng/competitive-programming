#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void print(vector<ll> &arr) {
    for (auto i: arr) cout << i << " ";
    cout << endl;
}

bool addDiscord(vector<ll> &arr, int i, int j) {
    ll left = arr[i];
    ll right = arr[j];
    string si = to_string(left);
    string sj = to_string(right);
    // if less digits, changing won't help
    if (si.size() < sj.size()) return false;
    
    // first try to raise LHS
    string a(si); a[0] = '9';
    ll newLeft = stoll(a);
    if (newLeft > right) {
        arr[i] = newLeft;
        return true;
    }

    if (sj.size() == 1 && left != 0) {
        arr[j] = 0;
        return true;
    }

    // next try to replace with one
    string b(sj); b[0] = '1';
    ll newRight = stoll(b);
    if (left > newRight) {
        arr[j] = newRight;
        return true;
    }
    
    // next try to replace remaining digits with zero
    string c(sj);
    for (int i = 1; i < c.size(); i++) {
        char tmp = c[i];
        c[i] = '0';
        newRight = stoll(c);
        if (left > newRight) {
            arr[j] = newRight;
            return true;
        }
        c[i] = tmp;
    }

    return false;
}

int main() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool sabotaged = false;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            // print(arr);
            sabotaged = addDiscord(arr, i, j);
            if (sabotaged) goto end;
        }
    }
    end:
    // print(arr);

    if (sabotaged) {
        for (ll &l: arr) cout << l << " ";
        cout << endl;
    } else {
        cout << "impossible" << endl;
    }
}