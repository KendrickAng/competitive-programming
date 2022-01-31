#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int left = 0;
    int right = 0;
    bool isLeft = true;
    while (cin >> c) {
        if (c == '(') {
            cin.ignore();
            isLeft = false;
        } else if (isLeft) {
            left++;
        } else {
            right++;
        }
    }
    if (left == right) cout << "correct" << endl;
    else cout << "fix" << endl;
}