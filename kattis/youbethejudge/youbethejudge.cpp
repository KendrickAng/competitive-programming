#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPrime(ll num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    char c;
    int count = 0;
    bool parsingNum = false;
    string str = "";
    while ((c = getchar()) != EOF) {
        str.push_back(c);

        if (!isspace(c) && !isdigit(c)) {
            // illegal character
            cout << 0 << endl;
            return 0;
        } else if (isdigit(c) && !parsingNum) {
            parsingNum = true;
            if (c == '0') {
                // no leading zeros allowed
                cout << 0 << endl;
                return 0;
            }
        } else if (isspace(c) && parsingNum) {
            parsingNum = false;
            count++;
            // too many numbers
            if (count > 3) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if (parsingNum) count++;

    if (count < 3) {
        // too few numbers
        cout << 0 << endl;
        return 0;
    }

    // guaranteed only 3 numbers, now proceed
    stringstream ss(str);
    ll first; ss >> first;
    if (first > 1e9 || first <= 3 || (first % 2) != 0) {
        // incorrect first number
        cout << 0 << endl;
        return 0;
    }

    ll second; ss >> second;
    if (second > first || second < 0) {
        // incorrect second number
        cout << 0 << endl;
        return 0;
    }

    ll third; ss >> third;
    if (c > first || third < 0) {
        // incorrect third number
        cout << 0 << endl;
    }

    int ans = isPrime(second) && isPrime(third) && (second + third == first);
    cout << ans << endl;
}