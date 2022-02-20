#include <bits/stdc++.h>

using namespace std;

#define var(x) {cout << #x << " = " << x << " " << endl;}
#define var2(x,y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define var3(x,y,z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}

void print(vector<int> &v) {
    for (int i: v) cout << i << ' '; cout << endl;
}

void printcard(vector<vector<int>> &v) {
    for (auto a: v) {
        for (auto b: a) {
            cout << b << ' ';
        }
        cout << endl;
    }
}

void solve() {
    int n; cin >> n;

    // read all cards
    vector<vector<vector<int>>> cards(n);
    for (int i = 0; i < n; i++) {
        // read one 5x5 card
        vector<vector<int>> card(5, vector<int>(5));
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                cin >> card[r][c];
            }
        }
        cards[i] = card;
    }

    vector<int> order;
    bool foundTie = false;
    int a, b;
    for (int i = 0; !foundTie && i < n; i++) {
        for (int j = i+1; !foundTie && j < n; j++) {
            // see if there is a matching character
            vector<vector<int>> &card1 = cards[i];
            vector<vector<int>> &card2 = cards[j];

            unordered_set<int> s1;
            unordered_map<int, int> numToRow;
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    int num = card1[r][c];
                    s1.insert(num);
                    numToRow[num] = r;
                }
            }

            for (int r = 0; !foundTie && r < 5; r++) {
                for (int c = 0; !foundTie && c < 5; c++) {
                    int num2 = card2[r][c];

                    // found a potential draw, extract
                    if (s1.find(num2) != s1.end()) {
                        unordered_set<int> numsToPick;

                        // retrieve cards from card 1
                        int row1 = numToRow[num2];
                        for (int row1Num: card1[row1]) {
                            if (row1Num == num2) continue;
                            numsToPick.insert(row1Num);
                        }
                        // retrieve cards from row 2
                        for (int row2Num: card2[r]) {
                            if (row2Num == num2) continue;
                            numsToPick.insert(row2Num);
                        }

                        order = vector<int>(numsToPick.begin(), numsToPick.end());
                        foundTie = true;
                        a = i+1;
                        b = j+1;
                    }
                }
            }
        }
    }

    // found potential answer, see if any other answers win first
    if (foundTie) {
        unordered_set<int> willbeCalled(order.begin(), order.end());
        for (int i = 0; foundTie && i < n; i++) {
            // check if there is a shorter winning sequence in this card
            vector<vector<int>> &card = cards[i];
            for (auto &row: card) {
                // is this row a winner?
                bool isWinner = true;
                for (auto num: row) {
                    isWinner = isWinner && (willbeCalled.find(num) != willbeCalled.end());
                }
                // shorter winning sequence found!
                if (isWinner) foundTie = false;
            }
        }
    }

    if (foundTie) cout << a << ' ' << b << endl;
    else cout << "no ties" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
