#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> page;
int rows, cols;

char SPECIAL = (char) 31;
char SPECIAL_BORDER = (char) 30;

bool isValid(int r, int c) {
    return r >= 0 and r < rows and c >= 0 and c < cols;
}

bool isImageStart(int r, int c) {
    return (isValid(r, c) and page[r][c] == '+' 
        and isValid(r, c+1) and page[r][c+1] == '+'
        and isValid(r+1, c) and page[r+1][c] == '+');
}

bool isImageEnd(int r, int c) {
    return (isValid(r, c) and page[r][c] == '+' 
        and isValid(r, c-1) and page[r][c-1] == '+'
        and isValid(r-1, c) and page[r-1][c] == '+');
}

bool isAllowedChar(int r, int c) {
    char ch = page[r][c];
    return ch == SPECIAL || ch == SPECIAL_BORDER || ch == '+' || ch == '?' || ch == '!' || ch == ',' || ch == '.' || ch == ' ' || isalnum(ch);
}

void discoverBorders(int r, int c, int &top, int &bot, int &left, int &right, set<pair<int,int>> &seen) {
    if (seen.find({r,c}) != seen.end()) return;
    // cout << "found border " << r << " " << c << endl;
    seen.insert({r,c});
    top = (top == -1) ? r : min(top, r);
    bot = (bot == -1) ? r : max(bot, r);
    left = (left == -1) ? c : min(left, c);
    right = (right == -1) ? c: max(right, c);
    vector<pair<int,int>> offsets = {{-1,0},{1,0},{0,-1},{0,1}};
    for (auto &[rOff, cOff]: offsets) {
        int newR = r + rOff;
        int newC = c + cOff;
        if (isValid(newR, newC) and page[newR][newC] == '+' and !seen.count({newR,newC})) {
            discoverBorders(newR, newC, top, bot, left, right, seen);
        }
    }
}

void removeAd(int r, int c, int adR, int adC) {
    if (!isValid(r, c) || page[r][c] == SPECIAL || page[r][c] == SPECIAL_BORDER) return;

    // potentially border of an image
    if (page[r][c] == '+') {
        int top = -1;
        int bot = -1;
        int left = -1;
        int right = -1;
        set<pair<int,int>> s;
        discoverBorders(r, c, top, bot, left, right, s);
        // cout << "t: " << top << " b: " << bot << " l: " << left << " r: " << right << endl;
        // cout << "r: " << r << " c: " << c << endl;

        // is actual border
        if (top < adR and bot > adR and left < adC and right > adC) {
            // cout << "found special border!" << endl;
            for (int rr = top; rr <= bot; rr++) {
                page[rr][left] = SPECIAL_BORDER;
                page[rr][right] = SPECIAL_BORDER;
            }
            for (int cc = left; cc <= right; cc++) {
                page[top][cc] = SPECIAL_BORDER;
                page[bot][cc] = SPECIAL_BORDER;
            }
            return;
        }
    }
    page[r][c] = SPECIAL;
    vector<pair<int,int>> offsets = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    for (auto &[rOff, cOff]: offsets) {
        int newR = r + rOff;
        int newC = c + cOff;
        if (isValid(newR, newC) and page[newR][newC] != SPECIAL and page[newR][newC] != SPECIAL_BORDER) {
            removeAd(newR, newC, adR, adC);
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
            // cout << page[r][c];
        }
        // cout << endl;
    }

    // cout << "read input successfully" << endl;

    // find points of ads
    bool inImage = false;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (isImageStart(r, c)) inImage = true;
            if (isImageEnd(r, c)) inImage = false;
            if (!isAllowedChar(r, c) and inImage) {
                // cout << "removing ad at " << r << " " << c << " " << page[r][c] << endl;
                removeAd(r, c, r, c);
            }
        }
    }

    //TODO print image
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            char ch = page[r][c];
            if (ch == SPECIAL || ch == SPECIAL_BORDER) {
                cout << ' ';
            } else {
                cout << ch;
            }
        }
        cout << endl;
    }
}