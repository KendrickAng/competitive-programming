// O(n2) approach

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> memo;
vector<int> arr;
vector<int> predecessor;

int LIS(int i) {
    if (i == 0) {
        return 1;
    }
    int ans = memo[i];
    if (ans != -1) return ans;
    ans = 1;
    for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i] && (LIS(j)+1 > ans)) {
            ans = memo[j] + 1;
            predecessor[i] = j;
        }
    }
    memo[i] = ans;
    return ans;
}

int main() {
    int tmp;
    while (cin >> tmp) {
        arr.push_back(tmp);
        predecessor.push_back(-1);
    }
    memo.resize(arr.size());
    fill(memo.begin(), memo.end(), -1);
    memo[0] = 1;
    
    int ans = LIS(arr.size()-1);
    cout << ans << endl;
    cout << '-' << endl;

    stack<int> stk;
    int pred = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (memo[i] == ans) {
            pred = i;
            break;
        }
    }
    while (pred != -1) {
        stk.push(arr[pred]);
        pred = predecessor[pred];
    }
    while (!stk.empty()) {
        cout << stk.top() << endl; stk.pop();
    }
}