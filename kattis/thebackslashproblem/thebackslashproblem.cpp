#include <iostream>
#include <cmath>

using namespace std;

bool isSpecial(char c) {
    return ((c >= '!') && (c <= '*')) || ((c >= '[') && (c <= ']'));
}

int main() {
    int n;
    string tmp;
    while (cin >> n) {
        getline(cin, tmp);
        string in = "";
        string out = "";
        getline(cin, in);
        int brackets = 0;
        for (int i = 0; i < n; i++) {
            brackets += pow(2, i);
        }

        for (auto c: in) {
            if (isSpecial(c)) {
                for (int i = 0; i < brackets; i++) {
                    out.push_back('\\');
                }
            }
            out.push_back(c);
        }
        cout << out << endl;
    }
}
