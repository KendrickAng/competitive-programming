#include <bits/stdc++.h>

using namespace std;

long long solveGreedy(vector<int> &a, vector<int> &b) {
    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += ((long long) a[i]*b[i]);
    return ans;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        long long ans = solveGreedy(a, b);
        cout << "Case #" << i << ": " << ans << endl;
    }
}

// long long solveBrute(vector<int> &a, vector<int> &b) {
//     int n = a.size();
//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());
//     long long ans = (long long) 100000*100000*800;
//     do {
//         do {
//             long long tmp = 0;
//             for (int i = 0; i < n; i++) {
//                 tmp += (long long) a[i]*b[i];
//             }
//             ans = min(ans, tmp);
//         } while(next_permutation(b.begin(), b.end()));
//     } while (next_permutation(a.begin(), a.end()));
    
//     return ans;
// }

// int rand(int a, int b) {
//     return a + rand() % (b - a + 1);
// }

// int main(int argc, char* argv[]) {
//     srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
//     for (int j = 0; j < 1000; j++) {
//         int n = rand(2, 7);
//         vector<int> a(n);
//         vector<int> b(n);
//         for (int i = 0; i < n; i++) a[i] = rand(-100000, 100000);
//         for (int i = 0; i < n; i++) b[i] = rand(-100000, 100000);
//         long long a1 = solveBrute(a, b);
//         long long a2 = solveGreedy(a, b);
//         if (a1 != a2) {
//             for (auto num: a) cout << num << " ";
//             cout << " brute gives " << a1 << endl;
//             for (auto num: b) cout << num << " ";
//             cout << " greedy gives " << a2 << endl;
//             break;
//         }
//     }
// }
