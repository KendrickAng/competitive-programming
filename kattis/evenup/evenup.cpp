#include <stack>
#include <iostream>

using namespace std;

int main() {
    stack<int> stk;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if (stk.empty()) {
            stk.push(tmp);
        }
        else if ((stk.top() + tmp) % 2 == 0) {
            stk.pop();
        }
        else {
            stk.push(tmp);
        }
    }
    cout << stk.size() << endl;
}
