#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    
    vector<pair<int,int>> restrictions;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        restrictions.push_back({a,b});
    }

    // try all subsets
    int ans = 0;
    for (int i = 0; i < (1<<n); i++) {
        bool ok = true;
        for (auto &[a,b]: restrictions) {
            if (((1 << a) & i) && ((1 << b) & i)) { // if both bits are on, restriction met
                ok = false; 
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;
}