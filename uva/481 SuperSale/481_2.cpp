// O(nlogk) approach

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A; // array of values
vector<int> p; // predecessor array

void print_LIS(int i) {
    if (p[i] == -1) {
        cout << A[i] << endl;
        return;
    }
    print_LIS(p[i]);
    cout << A[i] << endl;
}

int main() {
    int tmp;
    while (cin >> tmp) {
        A.push_back(tmp);
    }

    int n = A.size();
    int k = 0; 
    int lis_end = 0;
    vector<int> L(n, 0); // L[i] smallest ending value of all length-i increasing subsequences so far
    vector<int> L_id(n, 0); // L_id[i] = index of the smallest ending value of all length-i increasing subsequences so far
    p.assign(n, -1);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
        L[pos] = A[i];
        L_id[pos] = i; 
        p[i] = pos ? L_id[pos-1] : -1;
        if (pos == k) {
            k = pos+1;
            lis_end = i;
        }
    }

    cout << k << endl << '-' << endl;
    print_LIS(lis_end);
}