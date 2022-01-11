#include <iostream>
#include <algorithm>

using namespace std;

struct Team {
    bool hasReserve;
    bool isDamaged;
};

int ans = 100;

void solve(Team arr[], int len, int curr, int dmged) {
    if (curr >= len) {
        ans = min(ans, dmged);
        return;
    }
    Team &t = arr[curr];
    
    // keep to self, no backtracking
    if (t.isDamaged && t.hasReserve) {
        t.isDamaged = false;
        t.hasReserve = false;
        solve(arr, len, curr+1, dmged-1);
    } else if (t.hasReserve) {
        // lend to left
        if (curr > 0 && arr[curr-1].isDamaged) {
            Team &tl = arr[curr-1];
            t.hasReserve = false;
            tl.isDamaged = false;
            solve(arr, len, curr+1, dmged-1);
            t.hasReserve = true;
            tl.isDamaged = true;
        }

        // lend to right
        if (curr < len-1 && arr[curr+1].isDamaged) {
            Team &tr = arr[curr+1];
            t.hasReserve = false;
            tr.isDamaged = false;
            solve(arr, len, curr+1, dmged-1);
            t.hasReserve = true;
            tr.isDamaged = true;
        }

        solve(arr, len, curr+1, dmged);
    } else {
        solve(arr, len, curr+1, dmged);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s, r; cin >> n >> s >> r;
    Team teams[n];
    for (int i = 0; i < n; i++) {
        teams[i] = {false, false};
    }
    
    for (int i = 0; i < s; i++) {
        int tmp; cin >> tmp; tmp--;
        teams[tmp].isDamaged = true;
    }

    for (int i = 0; i < r; i++) {
        int tmp; cin >> tmp; tmp--;
        teams[tmp].hasReserve = true;
    }

    solve(teams, n, 0, s);
    cout << ans << endl;
}
