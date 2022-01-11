#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> multipliers = {11,111,1111,11111,111111,1111111,11111111,111111111};

long long gcd(long long a, long long b)
{
    if (!a)
       return b;
    return gcd(b%a,a);
}

long long gcdHelper(vector<int> vec, int vsize)
{
    long long g = vec[0];
    for (int i = 1; i < vsize; i++)
    {
        g = gcd(g, vec[i]);
    }
    return g;
}

bool solve(long s) {
    if (s < 111) {
        return s % 11 == 0;
    }
    vector<int> v{};
    for (int i: multipliers) {
        if (i <= s) {
            v.push_back(i);
        }
    }
    return (s % gcdHelper(v, v.size())) == 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // int t; cin >> t;
    // for (int tt = 0; tt < t; tt++) {
    //     long s; cin >> s;
        
    //     if (solve(s)) cout << "YES" << endl;
    //     else cout << "NO" << endl;
    // }
    long maxx = -1;
    unordered_set<long> mySet;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                for (int l = 1; l <= 10; l++) {
                    long num = i*11 + j*111 + k*1111 + l*11111;
                    cout << num << endl;
                }
            }
        }
    }
}

