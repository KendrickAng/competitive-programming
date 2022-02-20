#include <iostream>
#include <vector>

using namespace std;

int MAX_VALUE = 7500;
int MAX_TYPE = 5;

vector<int> COINS{50, 25, 10, 5, 1};
vector<vector<int>> memo(MAX_TYPE, vector<int>(MAX_VALUE, -1));

int dp(int type, int value) {
    if (value == 0) return 1;
    if (type >= (int) COINS.size() || value < 0) return 0;
    int& ans = memo[type][value];
    if (ans != -1) return ans;
    return ans = dp(type+1, value) + dp(type, value-COINS[type]);
}

int main() {
    int value;
    while (cin >> value) {
        cout << dp(0, value) << endl;
    }
}
