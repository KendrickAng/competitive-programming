#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board(8, vector<char>(8));
pair<int,int> myKing, myRook, theirKing;
vector<pair<int,int>> kingMoves = {
    {-1,-1},
    {-1,0},
    {-1,1},
    {0,-1},
    {0,1},
    {1,-1},
    {1,0},
    {1,1}
};

void print() {
    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[0].size(); c++) {
            cout << board[r][c];
        }
        cout << endl;
    }
}

void moveRook(int fromR, int fromC, int toR, int toC) {
    board[fromR][fromC] = '.';
    board[toR][toC] = 'R';
    myRook = {toR, toC};
}

void moveTheirKing(int fromR, int fromC, int toR, int toC) {
    board[fromR][fromC] = '.';
    board[toR][toC] = 'k';
    theirKing = {toR, toC};
}


bool isValid(int r, int c) {
    return r >= 0 and r < 8 and c >= 0 and c < 8;
}

bool kingsInContact() {
    int kr = myKing.first;
    int kc = myKing.second;
    int tr = theirKing.first;
    int tc = theirKing.second;
    for (auto [rOff, cOff]: kingMoves) {
        int newR = kr + rOff;
        int newC = kc + cOff;
        if (!isValid(newR, newC)) continue;
        if (newR == tr and newC == tc) return true;
    }
    return false;
}

bool theirKingDanger() {
    bool threatened = false;
    int newR = theirKing.first;
    int newC = theirKing.second;

    if (kingsInContact()) threatened = true;

    // threatened by myRook? - up
    for (int rr = newR; !threatened && rr >= 0; rr--) {
        if (board[rr][newC] == 'R') threatened = true;
    }

    // threatened by myRook? - down
    for (int rr = newR; !threatened && rr < 8; rr++) {
        if (board[rr][newC] == 'R') threatened = true;
    }

    // threatened by myRook? - left
    for (int cc = newC; !threatened && cc >= 0; cc--) {
        if (board[newR][cc] == 'R') threatened = true;
    }

    // threatened by myRook? - right
    for (int cc = newC; !threatened && cc < 8; cc++) {
        if (board[newR][cc] == 'R') threatened = true;
    }

    // if not threatened by this move, not checkmate
    return threatened;
}

bool checkmate() {
    if (!theirKingDanger()) return false;

    bool checkmate = true;

    int r = theirKing.first;
    int c = theirKing.second;
    board[r][c] = '.';

    // king tries to move first
    for (auto [rOff, cOff]: kingMoves) {
        int newR = r + rOff;
        int newC = c + cOff;
        if (!isValid(newR, newC)) continue;

        moveTheirKing(r, c, newR, newC);
        if (!theirKingDanger()) {
            checkmate = false;
        }
        moveTheirKing(newR, newC, r, c);
    }

    // if (checkmate) print();
    return checkmate;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'K') myKing = {i, j};
            if (board[i][j] == 'k') theirKing = {i, j};
            if (board[i][j] == 'R') myRook = {i, j};
        }
    }

    int r = myRook.first;
    int c = myRook.second;
    board[r][c] = '.';

    // try all rook moves - up
    for (int newR = r-1; newR >= 0; newR--) {
        moveRook(r, c, newR, c);
        if (checkmate()) {
            cout << "Yes" << endl;
            return 0;
        }
        moveRook(newR, c, r, c);
    }

    // down
    for (int newR = r+1; newR < 8; newR++) {
        moveRook(r, c, newR, c);
        if (checkmate()) {
            cout << "Yes" << endl;
            return 0;
        }
        moveRook(newR, c, r, c);
    }

    // left
    for (int newC = c-1; newC >= 0; newC--) {
        moveRook(r, c, r, newC);
        if (checkmate()) {
            cout << "Yes" << endl;
            return 0;
        }
        moveRook(r, newC, r, c);
    }

    // right
    for (int newC = c+1; newC < 8; newC++) {
        moveRook(r, c, r, newC);
        if (checkmate()) {
            cout << "Yes" << endl;
            return 0;
        }
        moveRook(r, newC, r, c);
    }

    // myRook = {r, c};
    // board[r][c] = 'R';
    
    cout << "No" << endl;
}