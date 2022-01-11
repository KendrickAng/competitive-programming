#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n; cin >> n;
    stack<bool> stk{};
    bool arr[26]{};
    for (int i = 0; i < n; i++) {
        char tmp; cin >> tmp;
        if (tmp == 'T') {
            arr[i] = true;
        }
        else {
            arr[i] = false;
        }
    }

    // read in the characters
    string line, token;
    getline(cin, line);
    getline(cin, line);
    istringstream ss(line);
    while (getline(ss, token, ' ')) {
        if (token == "*" || token == "+") {
            bool a = stk.top(); stk.pop();
            bool b = stk.top(); stk.pop();
            if (token == "*") {
                stk.push(a && b);
            }
            if (token == "+") {
                stk.push(a || b);
            }
        }
        else if (token == "-") {
            bool a = stk.top(); stk.pop();
            stk.push(!a);
        }
        else {
            int idx = (int) token[0] - (int) 'A';
            stk.push(arr[idx]);
        }
    }
    if (stk.top()) cout << "T" << endl;
    else cout << "F" << endl;
}