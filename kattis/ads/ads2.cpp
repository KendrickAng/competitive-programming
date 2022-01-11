#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int rows, cols;
vector<vector<char>> page;

bool isValid(int r, int c) {
    return r >= 0 and r < rows and c >= 0 and c < cols;
}

bool isImageStart(int r, int c) {
    return (isValid(r, c) and page[r][c] == '+' 
        and isValid(r, c+1) and page[r][c+1] == '+'
        and isValid(r+1, c) and page[r+1][c] == '+');
}

pii trace(int r, int c) {
    char curr = page[r][c];
    while (isValid(r, c+1) && page[r][c+1] == '+') c++;
    while (isValid(r+1, c) && page[r+1][c] == '+') r++;
    return {r, c};
}

bool isAllowedChar(int r, int c) {
    char ch = page[r][c];
    return ch == '+' || ch == '?' || ch == '!' || ch == ',' || ch == '.' || ch == ' ' || isalnum(ch);
}

void removeAd(pii topLeft, pii btmRight) {
    for (int r = topLeft.first; r <= btmRight.first; r++) {
        for (int c = topLeft.second; c <= btmRight.second; c++) {
            page[r][c] = ' ';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> rows >> cols; cin.ignore();
    page.resize(rows, vector<char>(cols));

    string line;
    for (int r = 0; r < rows; r++) {
        getline(cin, line);
        for (int c = 0; c < cols; c++) {
            page[r][c] = line[c];
        }
    }

    bool inImage = false;
    stack<pii> prevState;
    pii topLeft = {-1,-1};
    pii btmRight = {-1,-1};
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (isImageStart(r, c)) {
                if (topLeft.first != -1 && topLeft.second != -1) {
                    prevState.push(topLeft);
                    prevState.push(btmRight);
                }
                inImage = true;
                topLeft = {r,c};
                btmRight = trace(r, c);
            }
            if (btmRight.first == r && btmRight.second == c) {
                if (prevState.empty()) {
                    inImage = false;
                } else {
                    btmRight = prevState.top(); prevState.pop();
                    topLeft = prevState.top(); prevState.pop();
                }
            }
            if (!isAllowedChar(r, c) && inImage) {
                removeAd(topLeft, btmRight);
            }
        }
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << page[r][c];
        }
        cout << endl;
    }
}