#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using tiiii = tuple<int,int,int,int>;

int rows, cols;
vector<vector<char>> page;
vector<tiiii> ads;

bool isValid(int r, int c) {
    return r >= 0 and r < rows and c >= 0 and c < cols;
}

bool isImageStart(int r, int c) {
    return (isValid(r, c) and page[r][c] == '+' 
        and isValid(r, c+1) and page[r][c+1] == '+'
        and isValid(r+1, c) and page[r+1][c] == '+');
}

void trace(int r, int c, int &rr, int &cc) {
    char curr = page[r][c];
    while (isValid(r, c+1) && page[r][c+1] == '+') c++;
    while (isValid(r+1, c) && page[r+1][c] == '+') r++;
    rr = r;
    cc = c;
}

bool isAllowedChar(int r, int c) {
    char ch = page[r][c];
    return ch == '+' || ch == '?' || ch == '!' || ch == ',' || ch == '.' || ch == ' ' || isalnum(ch);
}

void findSmallest(int r, int c, pii &topLeft, pii &btmRight) {
    topLeft.first = -1;
    topLeft.second = -1;
    btmRight.first = -1;
    btmRight.second = -1;
    if (ads.empty()) return;
    for (auto &[r1, c1, r2, c2]: ads) {
        if (r1 < r && c1 < c && r2 > r && c2 > c) {
            // cout << "found a match" << endl;
            if (r1 > topLeft.first) {
                topLeft.first = r1;
                topLeft.second = c1;
                btmRight.first = r2;
                btmRight.second = c2;
            }
        }
    }
}

void removeAd(pii topLeft, pii btmRight) {
    // cout << "removing ad!" << endl;
    // cout << topLeft.first << " " << topLeft.second << endl;
    // cout << btmRight.first << " " << btmRight.second << endl;
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

    // find all images in the page
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (isImageStart(r, c)) {
                int rr, cc;
                trace(r, c, rr, cc);
                // cout << "found ad: " << r << " " << c << " " << rr << " " << cc << endl;
                ads.push_back({r,c,rr,cc});
            }
        }
    }

    // cout << ads.size() << endl;

    // remove all ads in the page
    pii topLeft, btmRight;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (!isAllowedChar(r, c)) {
                findSmallest(r, c, topLeft, btmRight);
                if (topLeft.first != -1 && topLeft.second != -1) {
                    removeAd(topLeft, btmRight);
                }
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