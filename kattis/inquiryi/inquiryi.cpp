#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long ans = -1;
    int n; cin >> n;
    vector<int> a{};
    long total_a = 0;
    vector<int> aa{};
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        total_a += tmp;
        a.push_back(tmp);
    }
    for (auto a: a) aa.push_back(a * a);
    long long aa_sum = 0;
    for (int i = 0; i < a.size(); i++) {
        aa_sum += aa[i];
        total_a -= a[i];
        ans = max(ans, aa_sum * total_a);
    }
    cout << ans << endl;
}