#include <iostream>
#include <string>

using namespace std;

void check(string &smallest, string s) {
    if ((s.size() >= 2) && ((smallest == "") || (s < smallest))) {
        smallest = s;
    }
}

int main() {
    int R, C; cin >> R >> C;
    char arr[R][C];
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> arr[r][c];
        }
    }

    string smallest = "";

    // iterate rows
    for (int r = 0; r < R; r++) {
        string s = "";
        for (int c = 0; c < C; c++) {
            if (arr[r][c] == '#') {
                check(smallest, s);
                s.erase();
                continue;
            }
            s.push_back(arr[r][c]);
        }
        check(smallest, s);
    }

    // iterate columns
    for (int c = 0; c < C; c++) {
        string s = "";
        for (int r = 0; r < R; r++) {
            if (arr[r][c] == '#') {
                check(smallest, s);
                s.erase();
                continue;
            }
            s.push_back(arr[r][c]);
        }
        check(smallest, s);
    }

    cout << smallest << endl;
}