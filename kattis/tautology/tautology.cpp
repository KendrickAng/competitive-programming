#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isOperand(char c) {
    return c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't';
}

bool isOperator(char c) {
    return c != 'N' && !isOperand(c);
}

// solves a postfix expression
bool solve(string input, int p, int q, int r, int s, int t) {
    stack<int> stk{};
    reverse(input.begin(), input.end());
    unordered_map<char, int> val = {
        {'p', p}, {'q', q}, {'r', r}, {'s', s}, {'t', t}
    };
    for (char c: input) {
        if (isOperand(c)) {
            stk.push(val[c]);
        }
        else if (isOperator(c)) {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            if (c == 'K') { // AND
                stk.push(a && b);
            }
            else if (c == 'A') { // OR
                stk.push(a || b);
            }
            else if (c == 'C') { // IMPLIES
                stk.push(!a || b);
            }
            else if (c == 'E') { // EQUALS
                stk.push(a == b);
            }
        }
        else {
            // NOT
            int a = stk.top(); stk.pop();
            stk.push(!a);
        }
    }
    return stk.top();
}

// string prefixToPostfix(string exp) {
//     stack<string> stk{};
//     reverse(exp.begin(), exp.end());
//     for (char c: exp) {
//         if (isOperand(c)) {
//             stk.push(string(1, c));
//         }
//         else if (isOperator(c)) {
//             string a = stk.top(); stk.pop();
//             string b = stk.top(); stk.pop();
//             stk.push(a + b + c);
//         } else {
//             // NOT
//             string a = stk.top(); stk.pop();
//             stk.push(a + c);
//         }
//     }
//     return stk.top();
// }

int main() {
    string input; cin >> input;
    // cout << prefixToPostfix(input) << endl;
    while (input != "0") {
        bool isTautology = true;
        for (int p = 0; p <= 1; p++) {
            for (int q = 0; q <= 1; q++) {
                for (int r = 0; r <= 1; r++) {
                    for (int s = 0; s <= 1; s++) {
                        for (int t = 0; t <= 1; t++) {
                            // string postfix = prefixToPostfix(input);
                            if (!solve(input, p, q, r, s, t)) {
                                isTautology = false;
                            }
                        }
                        if (!isTautology) break;
                    }
                    if (!isTautology) break;
                }
                if (!isTautology) break;
            }
            if (!isTautology) break;
        }
        if (isTautology) cout << "tautology" << endl;
        else cout << "not" << endl;

        cin >> input;
    }
}