#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input; cin >> input;
    string smallest = input;
    for (int i = 1; i < input.size(); i++) {
        for (int j = i+1; j < input.size(); j++) {
            string a = input.substr(0, i);
            string b = input.substr(i, j-i);
            string c = input.substr(j);
            // cout << a << " " << b << " " << c << endl;
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            string newStr = a + b + c;
            // cout << "new string: " << newStr << endl;
            if (lexicographical_compare(newStr.begin(), newStr.end(), smallest.begin(), smallest.end())) {
                smallest = newStr;
            }
        }
    }
    cout << smallest << endl;
}